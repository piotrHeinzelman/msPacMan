//
// Created by John on 2023-08-27.
//

#include "Board.h"
#include <vector>
#include <iostream>
#include "Mob.h"
#include "Bridges.h"
#include "UDPServ.h"
#include "UDPClient.h"
#include "Bridge.h"
#include <future>
#include <thread>

// THREAD LOCAL REFRESH
void RefreshBoard( Board* board ) {
    int i=0;
    while(true){
        board->showInfo( board->getPlayersMob() );
        board->clearAllUsedBridge();
        board->moveAllMobs();
        board->drawAllMob();
        board->drawDotsOfUsedBridge();

        i++;
        if (i%20==0)  board->allMobCheckcontroller();

        std::this_thread::sleep_for(std::chrono::milliseconds(1000/20));
    }
}



// THREAD LOCAL REFRESH
void ServerListen( Board* board ) {
    UDPServ serv( 8080 ); // port
    char readChar[255];
    int len;
    while( true ){
        len = serv.rec();
        std::cout << "rec: " << len << "bytes\n";
        //std::this_thread::sleep_for(std::chrono::milliseconds(1000/20));
    }
}





















/*
DWORD WINAPI BoardThreadFunc( Board* board ) {
    Mob* player = board->getPlayersMob();
    UDPServ ts=UDPServ(8080);
    char buf='.';
    while(1){
        std::this_thread::sleep_for(std::chrono::milliseconds(100 ));
        int len = ts.rec(); // odbior danych przez UDP
        if ( len==0 ) { continue; }

        switch( ts.getBuff()[0] ){
            case 'N': player->setDirection( DIRECT::N ); break;
            case 'S': player->setDirection( DIRECT::S ); break;
            case 'W': player->setDirection( DIRECT::W ); break;
            case 'E': player->setDirection( DIRECT::E ); break;
            default: break;
        }
        ts.setBuff( &buf );
        ts.snd();
    }
}
*/



void Board::PlayLocal() {

    prepare();
    drawBoard();
    drawAllDots();
    drawAllMob();

    // odrysowywanie do timer
        HANDLE thread = CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>( RefreshBoard ), this, 1, NULL);
    //    HANDLE thread2 = CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>( ServerListen ), this, 1, NULL);





    // LOCAL CONTROLLER
    Mob* player = getPlayersMob();
    DIRECT activeDirection=DIRECT::STOP;
    DIRECT d;
    while(true){
        if (GetKeyState(VK_NUMPAD8   ) < 0 ) { d=DIRECT::N; if (d != activeDirection ) { activeDirection=d; player->setNextDirection( d ); }}
        if (GetKeyState(VK_NUMPAD5 ) < 0 ) { d=DIRECT::S; if (d != activeDirection ) { activeDirection=d; player->setNextDirection( d ); }}
        if (GetKeyState(VK_NUMPAD4 ) < 0 ) { d=DIRECT::W; if (d != activeDirection ) { activeDirection=d; player->setNextDirection( d ); }}
        if (GetKeyState(VK_NUMPAD6) < 0 ) { d=DIRECT::E; if (d != activeDirection ) { activeDirection=d; player->setNextDirection( d ); }}
    }

}









































Board::Board() {
    //if (false)
    //HANDLE thread = CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(BoardThreadFunc), this, 1, NULL);
}






void Board::prepare() {


    cdraw.cls();

    Mob* Pinky= new Mob(0,  new Controller("Pinky",true ) , this);
    Mob* Inky=  new Mob(1, new Controller("Inky",true )  , this );
    Mob* Blinky=new Mob(2, new Controller("Blinky",true ) , this);
    Mob* Sue=   new Mob(3, new Controller("Sue",true ) , this);
    Mob* Pac=   new Mob(4, new Controller("Pac",false ) , this);
    player = Pac; // set Localplayer

    addMob(Pinky);
    addMob(Inky);
    addMob(Blinky);
    addMob(Sue);
    addMob(Pac);



    insertMobAtBridge(Pinky, 67 , 0);
    insertMobAtBridge(Inky, 71 , STEPS);
    insertMobAtBridge(Blinky, 67, STEPS);
    insertMobAtBridge(Sue, 71, 0);
    insertMobAtBridge(Pac, 189 , 3);



    Pinky->setDirection( DIRECT::W );
    Inky->setDirection( DIRECT::W );
    Blinky->setDirection( DIRECT::S );
    Sue->setDirection( DIRECT::E );
    Pac->setDirection( DIRECT::STOP );

    drawAllMob();

}






void Board::addMob( Mob* mob ){
    if ( mobs.size()>=8 ) return;
    mobs.push_back( mob );
}




void Board::insertMobAtBridge( Mob* mob , int bridgeNum , int step ){
            // isW = bridgeNum%2==1
    Bridge * pBridge = b.getBridgeByInt(bridgeNum);
    if ( pBridge==nullptr ) { throw std::runtime_error("nie ma takiego mostu!");}
    mob->setBridge( pBridge );
    mob->setStep( step );

    std::set<DIRECT> &set = mob->getExits(); set.clear();
    if( bridgeNum%2==1 ){
        set.insert(DIRECT::E ); set.insert(DIRECT::W );
    } else {
        set.insert(DIRECT::N ); set.insert(DIRECT::S );
    }
}


void Board::setMobDirection(Mob *mob, DIRECT direction) {
    if ( mob->getExits().count( direction )>0 ){
        mob->setDirection( direction );
    }
    showInfo( mob );
}

void Board::moveAllMobs(){
    for ( Mob* mob : mobs ){
        CheckTunnel( mob );
        mob->gotoNextStep();
        if (!mob->isGhost() && IsDotAt( mob->getAvatarPosition() ) ){
            // eat dot
            eatDot( mob );
        }
    }

    // check collision
       Mob* checkedMob    = nullptr;

      mobs.shrink_to_fit();
     for (int i=0;i<mobs.size();i++){
         checkedMob=mobs[i];
         for ( int j=i+1; j<mobs.size();j++){
            if ( checkedMob->getBridge()==mobs[j]->getBridge() ) {
                BoardCollision(checkedMob ,mobs[j] );
            }
         }
     }
}

void Board::eatDot( Mob* mob ){
    COORD point = mob->getAvatarPosition();
    if ( IsDotAt( point )){
        Dot* dot = getDotFrom( point );
        mob->addPoint( dot->getValue() );
        if ( dot->getPower()!=0 ){
            mob->addPower( dot->getPower() );
        }
        dots.erase( (256*point.X+point.Y)   );
    }
}





void Board::BoardCollision(Mob *one, Mob *two) {
    if ( one->getStep()==two->getStep() ) Collision( one, two );
}

void Board::Collision(Mob *one, Mob *two) {
    if ( one->isGhost() != two->isGhost() ){
        // fight !
        Mob* player = one->isGhost() ? two : one ;
        Mob* ghost = one->isGhost() ? one : two ;
        if ( player->getPower()==0 ){
             player->setBridge( b.getBridgeByInt(189 ));
             player->setLives( player->getLives()-1);
            // Immmortal ?
        } else {
            ghost->setBridge( b.getBridgeByInt(69));
            player->addPoint( 1000 );
        }
        //std::cout << "COLLISTION:" << one->getId() << " : " << two->getId();
    }
}



void Board::CheckTunnel(Mob *mob) {
    if ( mob->getBridge()->getBridgeNum()==101 && mob->getDirection()==DIRECT::W && mob->getStep()==3 ) { mob->setBridge( b.getBridgeByInt( 117 ) ); }
    if ( mob->getBridge()->getBridgeNum()==117 && mob->getDirection()==DIRECT::E && mob->getStep()==3 ) { mob->setBridge( b.getBridgeByInt( 101 ) ); }
}





void Board::drawDotsOfUsedBridge(){
    if (dots.empty()) { nextLevel(); }
    for ( Mob* mob : mobs ){
        drawDotsOfBridge( mob->getBridge() );
    }
}



void Board::drawAllMob(){
    for ( Mob* mob : mobs ){
        if (!mob->isGhost()) {mob->grabEnergy();}
        drawOneMob( mob );
    }
}



void Board::drawOneMob( Mob* mob ) {
    char avatar='P';//1;
    if ( mob->isGhost() ) { avatar='G';}
    if ( mob->getPower()>0 ) { avatar='#';}
    cdraw.WriteColourChar( mob->getAvatarPosition() , avatar );
}


void Board::clearAllUsedBridge() {
    for ( Mob* mob : mobs ){
        clearBridge( mob->getBridge() );
        drawDotsOfBridge( mob->getBridge() );
    }
}



void Board::clearBridge( Bridge* pB ){
    COORD startPoint = pB->getStartPoint();
    COORD endPoint   = pB->getEndPoint();

    int sx=startPoint.X;
    int sy=startPoint.Y;
    int ex=endPoint.X;
    int ey=endPoint.Y;
    for ( int x=sx; x<=ex ; x++ ){
        for ( int y=sy; y<=ey ; y++ ){
            cdraw.WriteColourChar( {static_cast<SHORT>(x),static_cast<SHORT>(y)} , ' ' );
        }
    }

}




void Board::allMobCheckcontroller() {
    for ( Mob* mob : mobs ) {
        mobCheckController(mob);
    }
}


void Board::mobCheckController( Mob* mob ) {
    if ( !mob->isGhost() ){
        if (GetAsyncKeyState(VK_UP) < 0) { mob->setNextDirection( DIRECT::N ); }
        if (GetAsyncKeyState(VK_DOWN) < 0) { mob->setNextDirection(  DIRECT::S ) ; }
        if (GetAsyncKeyState(VK_RIGHT) < 0) { mob->setNextDirection(  DIRECT::E ) ; }
        if (GetAsyncKeyState(VK_LEFT) < 0) { mob->setNextDirection(  DIRECT::W ) ; }
    }
    else {
        ghostIntel++;
        if (ghostIntel%10==3) mob->setDirection( DIRECT::N );
        if (ghostIntel%10==7) mob->setDirection( DIRECT::S );
        if (ghostIntel%11==4) mob->setDirection( DIRECT::W );
        if (ghostIntel%15==2) mob->setDirection( DIRECT::E );
    }
    cdraw.WriteColourChar({0,0}, (char) mob->getDirection());
    //std::cout << mob->getDirection();
}


Mob *Board::getPlayersMob() {
    for ( Mob* mob : mobs ){
        if( !mob->isGhost() ) return mob;
    }
    return nullptr;
}








void Board::showInfo( Mob* mob ){
    if (mob->getLives()==0) {
            mob->gameOver();
            for (auto it = mobs.begin(); it != mobs.end(); ++it ) {
            if ( mob==*it ) {
                mobs.erase(it);
            }
        }
    }
    for (int i=0;i<mob->getLives();i++){
        COORD point={static_cast<SHORT>(i+1),24};
        cdraw.WriteColourChar( point, 'C', 0x90 );
        cdraw.WriteColourChar( {static_cast<SHORT>(point.X+1),point.Y}, ' ', 0x90 );
        cdraw.WriteColourChar( {static_cast<SHORT>(point.X+2),point.Y}, ' ', 0x90 );
    }
    //cdraw.WriteColourChar( { 20, 24 }, 0x30+(dots.size()/10), 0x90 );
    // cdraw.WriteColourChar( { 21, 24 }, 0x30+(dots.size()%10), 0x90 );

    int pts=mob->getPoints();

    int x=52;
    while ( pts>0 ){
        cdraw.WriteColourChar( { (SHORT) x, -2 }, 0x30+(pts%10), 0x90 );
        x--;
        pts=pts/10;
    }
}





void Board::drawBoard() {
    
    int LIMIT = 240;  std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    b.drawAllWalls();

    createDot(1 , { 2,0 } , true , 50 , 1000 );
    createDot(17 , { 54,0 } , true , 50 , 1000 );
    createDot(221 , { 2,22 } , true , 50 , 1000 );
    createDot(237 , { 54,22 } , true , 50 , 1000 );

    for ( Bridge* bridge : b.getAllBridges() ){
        if ( bridge->getBridgeNum()!=117 && bridge->getBridgeNum()!=101 )
        createDot( bridge->getBridgeNum() , bridge->getCenterPoint() , bridge->isW() , 5,0 ); // normal dot, value 1 power 0
    }

      drawAllDots();
}


Dot* Board::createDot( int i , COORD center , bool isW , int value, int power) {
    Dot* dot = new Dot( i, center , value , power ) ;
    int key = 256*center.X + center.Y;
    dots[key]=dot;
    return dot;
}

Dot* Board::getDotFrom(COORD point ){
    return dots[256*point.X+point.Y];
    }

bool Board::IsDotAt( COORD point ){
    return dots.count(256*point.X+point.Y)>0;
}

void Board::drawAllDots(){
    for ( std::pair<const int, Dot *> pair : dots ){
        drawOneDot( pair);
    }
}

void Board::drawOneDot( std::pair<const int, Dot *> pair ){
    int dot=250;
    if ( pair.second->getPower()>0 ) { dot='o'; } //249
    cdraw.WriteColourChar( (SHORT) pair.first/256 , (SHORT)pair.first%256 , dot);
}

void Board::drawDotsOfBridge( Bridge* bridge ){
    COORD startPoint = bridge->getStartPoint();
    COORD endPoint   = bridge->getEndPoint();
    int sx=startPoint.X;
    int sy=startPoint.Y;
    int ex=endPoint.X;
    int ey=endPoint.Y;
    for ( int x=sx; x<=ex ; x++ ){
        for ( int y=sy; y<=ey ; y++ ){
            if ( IsDotAt( {  static_cast<SHORT>(x),  static_cast<SHORT>(y)} ) ) {
                Dot* dot = getDotFrom({static_cast<SHORT>(x),static_cast<SHORT>(y)} );
                std::pair<const int, Dot *> pair = { 256*x+y , dot };
                drawOneDot(  pair );
            }
        }
    }
}

void Board::nextLevel() {
    prepare();
    drawBoard();
}

void Board::PlayServer(std::string ip) {

}














