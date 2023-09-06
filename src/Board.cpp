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


Board::Board() {
    if (false)
    HANDLE thread = CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(BoardThreadFunc), this, 1, NULL);
}



void Board::prepare() {

    Mob* Pinky= new Mob(0,  "Pinky" , this, true );
    Mob* Inky=  new Mob(1, "Inky" , this, true );
    Mob* Blinky=new Mob(2, "Blinky", this, true);
    Mob* Sue=   new Mob(3, "Sue", this, true);
    Mob* Pac=   new Mob(4, "Pac", this, false );
    player = Pac; // set Localplayer

    addMob(Pinky);
    addMob(Inky);
    addMob(Blinky);
    addMob(Sue);
    addMob(Pac);



    insertMobAtBridge(Pinky, 7 , 0);
    insertMobAtBridge(Inky, 7 , 3);
    insertMobAtBridge(Blinky, 7, STEPS);
    insertMobAtBridge(Sue, 151, 3);
    insertMobAtBridge(Pac, 1 , 3);



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
    Bridge* checkedBridge = nullptr;
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



void Board::Collision(Mob *one, Mob *two) {
    std::cout << "COLLISTION:" << one->getId() << " : " << two->getId();
}

void Board::BoardCollision(Mob *one, Mob *two) {

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
    for (int i=0;i<mob->getLives();i++){
        COORD point={static_cast<SHORT>(i+1),24};
        cdraw.WriteColourChar( point, 2, 0x90 );
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
        createDot( bridge->getBridgeNum() , bridge->getCenterPoint() , 1 , 0 ); // normal dot, value 1 power 0
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
}
















