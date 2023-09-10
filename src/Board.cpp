
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

        board->allControllerCheckTick();

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
   // drawAllMob();


    // odrysowywanie do timer
        HANDLE thread = CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>( RefreshBoard ), this, 1, NULL);
    //    HANDLE thread2 = CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>( ServerListen ), this, 1, NULL);

    std::cout<<"AAA\n";
    return;



    // LOCAL CONTROLLER
    Controller* player = getPlayersMob();
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

    Controller* CPinky = new Controller( "Pinky", true, getBridgeFrom(67)  );
// Controller* CInky = new Controller( "Inky", true, getBridgeFrom(71)  );
//    Controller* CBlinky = new Controller( "Blinky", true, getBridgeFrom(67)  );
//    Controller* CSue = new Controller( "Sue", true, getBridgeFrom(67)  );

    Controller* CPac = new Controller( "Pac", false, getBridgeFrom(189)  );

    player = CPac; // set Localplayer

    addMob(CPinky); CPinky->setDirection( DIRECT::E );
//    addMob(CInky);CPinky->setDirection( DIRECT::E );
//    addMob(CBlinky);CPinky->setDirection( DIRECT::E );
//    addMob(CSue);CPinky->setDirection( DIRECT::E );
    addMob(CPac); CPac->setDirection( DIRECT::E );

    drawAllMob();

}






void Board::addMob( Controller* Cmob ){
    if ( controllers.size()>=8 ) return;
    controllers.push_back( Cmob );
}




void Board::insertMobAtBridge( Controller* Cmob , int bridgeNum , int step ){
            // isW = bridgeNum%2==1
    Bridge * pBridge = b.getBridgeByInt(bridgeNum);
    if ( pBridge==nullptr ) { throw std::runtime_error("nie ma takiego mostu!");}
    Cmob->setBridge( pBridge );
    Cmob->setStep( step );
}


void Board::moveAllMobs(){
    for ( Controller* Cmob : controllers ){
        CheckTunnel( Cmob );
        Cmob->gotoNextStep();
        if (!Cmob->isGhost() && IsDotAt( Cmob->getAvatarPosition() ) ){
            // eat dot
            eatDot( Cmob );
        }
    }

    // check collision
       Controller* checkedMob    = nullptr;

    controllers.shrink_to_fit();
     for (int i=0;i<controllers.size();i++){
         checkedMob=controllers[i];
         for ( int j=i+1; j<controllers.size();j++){
            if ( checkedMob->getBridge()==controllers[j]->getBridge() ) {
                BoardCollision(checkedMob ,controllers[j] );
            }
         }
     }
}

void Board::eatDot( Controller* Cmob ){
    COORD point = Cmob->getAvatarPosition();
    if ( IsDotAt( point )){
        Dot* dot = getDotFrom( point );
        Cmob->getMob()->addPoint( dot->getValue() );
        if ( dot->getPower()!=0 ){
            Cmob->getMob()->addPower( dot->getPower() );
        }
        dots.erase( (256*point.X+point.Y)   );
    }
}





void Board::BoardCollision(Controller *one, Controller *two) {
    if ( one->getStep()==two->getStep() ) Collision( one, two );
}

void Board::Collision(Controller *one, Controller *two) {
    if ( one->isGhost() != two->isGhost() ){
        // fight !
        Controller* player = one->isGhost() ? two : one ;
        Controller* ghost = one->isGhost() ? one : two ;
        if ( player->getMob()->getPower()==0 ){
             player->setBridge( b.getBridgeByInt(189 ));
             player->getMob()->setLives( player->getMob()->getLives()-1);
            // Immmortal ?
        } else {
            ghost->setBridge( b.getBridgeByInt(69));
            player->getMob()->addPoint( 1000 );
        }
        //std::cout << "COLLISTION:" << one->getId() << " : " << two->getId();
    }
}



void Board::CheckTunnel(Controller* Cmob) {
    if ( Cmob->getBridge()->getBridgeNum()==101 && Cmob->getDirection()==DIRECT::W && Cmob->getStep()==3 ) { Cmob->setBridge( b.getBridgeByInt( 117 ) ); }
    if ( Cmob->getBridge()->getBridgeNum()==117 && Cmob->getDirection()==DIRECT::E && Cmob->getStep()==3 ) { Cmob->setBridge( b.getBridgeByInt( 101 ) ); }
}





void Board::drawDotsOfUsedBridge(){
    if (dots.empty()) { nextLevel(); }
    for ( Controller* Cmob : controllers ){
        drawDotsOfBridge( Cmob->getBridge() );
    }
}



void Board::drawAllMob(){
    for ( Controller* Cmob : controllers ){
        if (!Cmob->isGhost()) {Cmob->getMob()->grabEnergy();}
        drawOneMob( Cmob );
    }
}



void Board::drawOneMob(Controller* Cmob ) {
    char avatar=Cmob->getAvatarCode();
    if ( Cmob->getMob()->getPower()>0 ) { avatar='#';}
    cdraw.WriteColourChar( Cmob->getAvatarPosition() , avatar );
}


void Board::clearAllUsedBridge() {
    for ( Controller* Cmob : controllers ){
        clearBridge( Cmob->getBridge() );
        drawDotsOfBridge( Cmob->getBridge() );
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




void Board::allControllerCheckTick() {
    for ( Controller* Cmob : controllers ) {
        Cmob->checkTick( Cmob );
    }
}


Controller* Board::getPlayersMob() {
    for ( Controller* Cmob : controllers ){
        if( !Cmob->isGhost() ) return Cmob;
    }
    return nullptr;
}








void Board::showInfo(Controller* Cmob ){
    if (Cmob->getMob()->getLives()==0) {
        Cmob->getMob()->gameOver();
            for (auto it = controllers.begin(); it != controllers.end(); ++it ) {
            if ( Cmob==*it ) {
                controllers.erase(it);
            }
        }
    }
    for (int i=0;i<Cmob->getMob()->getLives();i++){
        COORD point={static_cast<SHORT>(i+1),24};
        cdraw.WriteColourChar( point, 'C', 0x90 );
        cdraw.WriteColourChar( {static_cast<SHORT>(point.X+1),point.Y}, ' ', 0x90 );
        cdraw.WriteColourChar( {static_cast<SHORT>(point.X+2),point.Y}, ' ', 0x90 );
    }
    //cdraw.WriteColourChar( { 20, 24 }, 0x30+(dots.size()/10), 0x90 );
    // cdraw.WriteColourChar( { 21, 24 }, 0x30+(dots.size()%10), 0x90 );

    int pts=Cmob->getMob()->getPoints();

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

Bridge* Board::getBridgeFrom(int i) {
    return b.getBridgeByInt( i );
}












