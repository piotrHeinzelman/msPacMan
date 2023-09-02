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
#include "TickRunner.h"
#include "Keyb.h"
#include <future>



Board::Board() {
    //prepare();
    //RunBoardTick();
}


// THREAD !
DWORD runTickInThread( Board* b ){
    while(true){
        std::this_thread::sleep_for(std::chrono::milliseconds(100 ));
        //b->BoardTick();
        b->ServerTick();
        //std::this_thread::sleep_for(std::chrono::milliseconds(100 ));
    }
    return 0;
}

void Board::RunBoardTick() {
    //std::thread t( runTickInThread, this  );
    //std::thread t( runTickInThread, this  );
    std::async( runTickInThread, this  );
}



void Board::ServerTick(){

        int len = ts.rec(); // odbior danych przez UDP
        if ( len==0 ) return;
        char buf='.';

        //std::cout << ts.getBuff();

        switch( ts.getBuff()[0] ){
            case 'N': player->setDirection( DIRECT::N ); break;
            case 'S': player->setDirection( DIRECT::S ); break;
            case 'W': player->setDirection( DIRECT::W ); break;
            case 'E': player->setDirection( DIRECT::E ); break;
            default: break;
        }
        ts.setBuff( &buf );
        ts.snd();
        return;
}

void Board::BoardTick(){
    //allMobCheckControllers();
    clearAllUsedBridge();
    moveAllMobs();
    drawAllMob();
        //std::cout << "BoardTick";
        std::this_thread::sleep_for(std::chrono::milliseconds(200 ));
}



void Board::prepare() {

    Mob* Pinky= new Mob(0,  "Pinky" , this, true );
    Mob* Inky=  new Mob(1, "Inky" , this, true );
    Mob* Blinky=new Mob(2, "Blinky", this, true);
    Mob* Sue=   new Mob(3, "Sue", this, true);
    Mob* Pac=   new Mob(4, "Pac", this );
    player = Pac;

    addMob(Pinky);
    addMob(Inky);
    addMob(Blinky);
    addMob(Sue);
    addMob(Pac);



    insertMobAtBridge(Pinky, 189 , 3 , true );
    insertMobAtBridge(Inky, 189 , 3 , true );
    insertMobAtBridge(Blinky, 189, 3 , true );
    insertMobAtBridge(Sue, 189, 3 , true );
    insertMobAtBridge(Pac, 5 , 0 , true );



    Pinky->setDirection( DIRECT::N );
    Inky->setDirection( DIRECT::W );
    Blinky->setDirection( DIRECT::S );
    Sue->setDirection( DIRECT::E );
    Pac->setDirection( DIRECT::E );

    drawAllMob();
}






void Board::addMob( Mob* mob ){
    if ( mobs.size()>=8 ) return;
    mobs.push_back( mob );
}




void Board::insertMobAtBridge( Mob* mob , int bridge , int step , bool isW ){
    mob->setBridge( bridge );
    mob->setStep( step );
    mob->isW( isW );
    std::set<DIRECT> &set = mob->getExits(); set.clear();
    if( isW ){
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
        moveMobNextStep( mob );
    }
}


void Board::moveMobNextStep( Mob* mob ){
        int step=mob->getStep();
        if ( mob->isW() ){
            if ( mob->getDirection()==DIRECT::E ) { step++ ; }
            if ( mob->getDirection()==DIRECT::W ) { step-- ; }
        } else {
            if ( mob->getDirection()==DIRECT::S ) { step++; }
            if ( mob->getDirection()==DIRECT::N ) { step--; }
        }
        mob->setStep(step);

        // in range
        if ( mob->getStep()>=0 && mob->getStep()<=STEPS) return;
        // out range
        bool onStart=false;
        if ( mob->getStep()<0 ) { mob->setStep(0); onStart=true; } else { mob->setStep(STEPS); }
        int edge = b.edgeChessPosition( mob->getBridge(), onStart );
        mob->getExits() = b.getAllWaysFromEdge( edge );
        //nextDirection
        if ( mob->getExits().count(mob->getNextDirection())>0 && mob->getNextDirection()!=DIRECT::STOP ){ mob->setDirection( mob->getNextDirection()); mob->setNextDirection( DIRECT ::STOP );  }
        if ( mob->getExits().count(mob->getDirection())>0 ){
            moveMobNextBridge( mob , onStart );
        }
}



void Board::moveMobNextBridge( Mob* mob , bool onStart ){
    int actualBridgeNum = mob->getBridge();
    int edge = b.edgeChessPosition( actualBridgeNum,  onStart );
    if ( b.isExistsWayFromEdge( edge, mob->getDirection() ) ){
        int nextBridge = b.getWayFromEdge(edge, mob->getDirection());
        mob->setBridge(nextBridge);
        if ( mob->getStep()==0 ) { mob->setStep(STEPS); } else { mob->setStep(0); }
        mob->isW( b.isW( mob->getBridge()));
    }
}


void Board::drawAllMob(){
    for ( Mob* mob : mobs ){
        drawOneMob( mob );
    }
}



void Board::drawOneMob( Mob* mob ) {
    int edgeStart = b.edgeChessPosition( mob->getBridge() , true );
    COORD startPoint = b.getCoordOfEdge(edgeStart);

    //std::cout << startPoint.X << ", y: " << startPoint.Y ;

    int mobX = startPoint.X;
    int mobY = startPoint.Y;
    // correction  point
    if ( mob->isW() ){
        mobX += mob->getStep();
    } else {
       if (mob->getStep()>1) mobY++;
       if (mob->getStep()>4) mobY++;
    }

    char avatar='P';//1;
    if ( mob->isGhost() ) { avatar='G'/*2*/;}
    cdraw.WriteColourChar( mobX , mobY , avatar );
}


void Board::clearAllUsedBridge() {
    for ( Mob* mob : mobs ){
        clearBridge( mob->getBridge() );
    }
}



void Board::clearBridge( int i ){
    int start = b.edgeChessPosition( i, true );
    int end =   b.edgeChessPosition( i, false );
    COORD startPoint = b.getCoordOfEdge( start );
    COORD endPoint   = b.getCoordOfEdge( end );
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


void Board::allMobCheckControllers() {
    for ( Mob* mob : mobs ){
        mobCheckController( mob );
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
        if (ghostIntel%10==3) mob->setDirection( DIRECT::S );
        if (ghostIntel%10==3) mob->setDirection( DIRECT::W );
        if (ghostIntel%10==3) mob->setDirection( DIRECT::E );
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
    std::cout << "id:" << mob->getId()<<"\n";
}




















void Board::drawBoard() {
    
    int LIMIT = 240;  std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

        for (int i = 0; i < LIMIT; i++) {  // walls
            if ( !b.isExsits( i ) ) { continue; }
            COORD center = b.getCoordOfCenterBridge( i );
            createDot( i , center , b.isW( i ));
            if ( b.isW(i)) {
                createDot( i , {static_cast<SHORT>((center.X-3)),center.Y} , b.isW( i ));
                createDot( i , {static_cast<SHORT>((center.X+3)),center.Y} , b.isW( i ));
            }
            b.DrawWall( i );
        }

    createDot(1 , { 2,0 } , true , 50 , 1000 );
    createDot(17 , { 54,0 } , true , 50 , 1000 );
    createDot(221 , { 2,22 } , true , 50 , 1000 );
    createDot(237 , { 54,22 } , true , 50 , 1000 );

      drawAllDots();
}


Dot* Board::createDot( int i , COORD center , bool isW , int value, int power) {
    Dot* dot = new Dot( i, center , value , power ) ;
    int key = 256*center.X + center.Y;
    dots[key]=dot;
    return dot;
}

Dot * Board::getDotFrom(COORD point ){
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

void Board::drawDotsOfBridge( int i ){
    int start = b.edgeChessPosition( i, true );
    int end =   b.edgeChessPosition( i, false );
    COORD startPoint = b.getCoordOfEdge( start );
    COORD endPoint   = b.getCoordOfEdge( end );
            if (false) {
              std::cout << "start:" << start << ", startPiont: " << startPoint.X << "," << startPoint.Y  << "\n";
              std::cout << "end:" << end << ", endPiont: " << endPoint.X << "," << endPoint.Y  << "\n"; }
    int sx=startPoint.X;
    int sy=startPoint.Y;
    int ex=endPoint.X;
    int ey=endPoint.Y;
    for ( int x=sx; x<=ex ; x++ ){
        for ( int y=sy; y<=ey ; y++ ){
            //std::cout << "point:" << x << ", " << y <<   "\n";
            //check dot at x,y
            if ( IsDotAt( {  static_cast<SHORT>(x),  static_cast<SHORT>(y)} ) ) {
                Dot* dot = getDotFrom({static_cast<SHORT>(x),static_cast<SHORT>(y)} );
                std::pair<const int, Dot *> pair = { 256*x+y , dot };
                drawOneDot(  pair );
            }
        }
    }
}

void Board::eatDot( Mob* mob , COORD point ){
    if ( IsDotAt( point )){
        Dot* dot = getDotFrom( point );
        mob->addPoint( dot->getValue() );
        if ( dot->getPower()!=0 ){
            mob->addPower( dot->getPower() );
        }
    }
}




void Board::redrawAllBridge(){
    for (int i=0;i<8;i++){
        redrawBridge ( activeBridges[i]);
    }
}

void Board::redrawBridge( int bridgeNum ){
    clearBridge( bridgeNum );
    b.DrawWall( bridgeNum );
    drawDotsOfBridge ( bridgeNum );
    //drawAllMobOnBridge ( bridgeNum );
}

HANDLE Board::getHandle() {
    return cdraw.getHandle();
}

void Board::CreateServer(Mob *mob) {
    UDPServ ts = UDPServ(8080 );
    ts.rec(); // odbior danych przez UDP
    player = mob;
    //std::cout << mob->getPoints();

            //ts.rec(); // odbior danych przez UDP

            /*

        bool guard=false;
        while( !guard ){
            ts.rec(); // odbior danych przez UDP
            std::cout << ts.getBuff();

            switch( ts.getBuff()[0] ){
                case 'N': mob->setDirection( DIRECT::N ); break;
                case 'S': mob->setDirection( DIRECT::S ); break;
                case 'W': mob->setDirection( DIRECT::W ); break;
                case 'E': mob->setDirection( DIRECT::E ); break;
                default: break;
            }
            ts.setBuff(".");
            ts.snd();
            usleep(10000);
            //printf( "S<%s\n",ts.getBuff() );
        }
        printf("Koncze!\n");
        */
}














