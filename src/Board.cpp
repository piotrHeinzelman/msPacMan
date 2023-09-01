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


DWORD runTickInThread( Board* b ){
    while(true){
        b->BoardTick();
        std::this_thread::sleep_for(std::chrono::milliseconds(100 ));
    }
    return 0;
}


Board::Board() {
    prepare();

}

void Board::prepare() {
    Mob* Pinky= new Mob(0, (std::string) "Pinky" , true );
    Mob* Inky=  new Mob(1, (std::string)"Inky" , true );
    Mob* Blinky=new Mob(2, (std::string)"Blinky", true);
    Mob* Sue=   new Mob(3, (std::string)"Sue", true);
    Mob* Pac=   new Mob(4, (std::string)"Pac");


    mobiles[Pinky->getId()]= Pinky ;
    mobiles[Inky->getId()]= Inky;
    mobiles[Blinky->getId()]= Blinky;
    mobiles[Sue->getId()]= Sue;
    mobiles[Pac->getId()]= Pac;



    setMobAt( Pinky->getId() , 5 ); Pinky->setPositionOnBridge(1);
    setMobAt( Inky->getId() , 15 ); Inky->setPositionOnBridge(2);
    setMobAt( Blinky->getId() , 101 ); Blinky->setPositionOnBridge(3);
    setMobAt( Sue->getId() , 84 ); Sue->setPositionOnBridge(4);
    setMobAt( Pac->getId() , 187 );
    Pinky->setPositionOnBridge(0);
    Inky->setPositionOnBridge(0);
    Blinky->setPositionOnBridge(0);
    Sue->setPositionOnBridge(0);
    Pac->setPositionOnBridge(0);

    Pinky->setParent( this );
    Inky->setParent( this );
    Blinky->setParent( this );
    Sue->setParent( this );
    Pac->setParent( this );

    Pinky->setDirection( DIRECT::N );
    Inky->setDirection( DIRECT::W );
    Blinky->setDirection( DIRECT::S );
    Sue->setDirection( DIRECT::E );
    Pac->setDirection( DIRECT::E );



    // dla wszystkich MOB pokaz mosty, cyklicznie przesuwaj


    drawBoard();
    drawAllDots();
    drawAllMob();


    std::thread t( runTickInThread, this );
    t.join();

    sleep(15);

}


void Board::BoardTick(){
    Keyb k;
    Mob* mob=getMobPac();
    while(true){
        //std::cout << "BoardTick";
        mob->setDirection( k.read());
        moveAllMobs();
        redrawAllBridge();
        void drawAllMob();
        std::this_thread::sleep_for(std::chrono::milliseconds(100 ));
    }
}

Mob* Board::getMobPac(){
    return mobiles[4];
}

int Board::getBridgeNumOfMobId( int mobId ){
    return activeBridges[mobId];
}

void Board::setMobAt( int mobId, int bridgeNum ) {  // postać zawsze na jednym akrywnym moście - o numerze unsigned int = activeBridges[ idPostaci ];
    activeBridges[mobId]=bridgeNum;
    activateBridge( activeBridges[mobId] );
    //std::cout << "Board:: setMob("<< mobId << ") at: " << activeBridges[mobId]<<"\n";
}


void Board::moveMobTo(int mobId, DIRECT direction, int bridgeNum) {
    deactivateBridge( activeBridges[ mobId ] );
    activeBridges[ mobId ]=bridgeNum;
    activateBridge( activeBridges[ mobId ] );
}





void Board::showInfo(){
    cdraw.WriteColourChar( 5,55 ,'x');
}












DIRECT Board::atEdge(int id, DIRECT direction, DIRECT nextDirection) {
    //std::cout<<"Board::atEdge("<<id<<" , id: " << mobiles[id]->getPositionOnBridge() <<  ");\n";


    int ActualPosition=activeBridges[id];
    int next = ActualPosition+direction;
    if ( next > 0 && next < 255 && activeBridges[next]==' '){
        // nastepny most nie istnieje
        next = ActualPosition+nextDirection;
        if ( next > 0 && next < 255 && activeBridges[next]==' '){ mobiles[id]->setDirection( STOP ); }
    }
    //std::cout<<"Board::atEdge("<<id<<");";
    return DIRECT::STOP;
}







void Board::activateBridge(int bridgeNum) {};
void Board::deactivateBridge(int bridgeNum) {}



void Board::drawBoard() {
    
    int LIMIT = 240;  std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

        for (int i = 0; i < LIMIT; i++) {  // walls
            if ( !b.isExsits( i ) ) { continue; }
            COORD center = b.getCoordOfCenterBridge( i );
            createDot( i , center , b.isW( i ));
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



void Board::drawAllMob(){
    for ( int i=0;i<8;i++){ // for all Mobiles slot
        if ( mobiles[i]!= nullptr ){
            drawOneMob( mobiles[i]->getId() );
        }
    }
}

void Board::drawOneMob(int mobId) {
    Mob* mob = mobiles[mobId];
    int mobBridge = getBridgeNumOfMobId( mobId );
    int start = b.edgeChessPosition( mobBridge , true );
    int end   = b.edgeChessPosition( mobBridge , false );
    //std::cout << "start:" << start << ", end:" << end << "\n";

    COORD startPoint = b.getCoordOfEdge(start);
    COORD endPoint = b.getCoordOfEdge(end);
    //std::cout << "MobId:" << mobId << "\n";
    //std::cout << "sx:" << startPoint.X << ", sy:" << startPoint.Y << "\n";
    //std::cout << "ex:" << endPoint.X << ", ey:" << endPoint.Y << "\n";
    int bridgeDistanceX = endPoint.X - startPoint.X;
    int bridgeDistanceY = endPoint.Y - startPoint.Y;
    int mobX = startPoint.X  + mob->getPositionOnBridge(); //( bridgeDistanceX * mob->getPositionOnBridge() / STEPS );
    int mobY = startPoint.Y  + mob->getPositionOnBridge();// ( bridgeDistanceY * mob->getPositionOnBridge() / STEPS );
    //std::cout << "pos:"<< mobX << "\n\n";

    char avatar='P';//1;
    if ( mob->isGhost() ) { avatar='G'/*2*/;}
    cdraw.WriteColourChar( mobX , mobY , avatar );


    //std::cout << "pos." << mob->getPositionOnBridge() << ", mobX: " << mobX << "\n";


}





void Board::moveAllMobs(){
    for ( int i=0;i<8;i++){ // for all Mobiles slot
        if ( mobiles[i]!= nullptr ){
            moveOneMob( mobiles[i]->getId() );
        }
    }
}



void Board::moveOneMob( int mobId ){
    mobiles[mobId]->step();
}