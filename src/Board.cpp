//
// Created by John on 2023-08-27.
//

#include "Board.h"
#include <vector>
#include <iostream>
#include "Mob.h"
#include "Bridges.h"

Board::Board() {

    prepare();
}

void Board::prepare() {
    //Mob* Pinky= new Mob(0, (std::string) "Pinky" );
    //Mob* Inky=  new Mob(1, (std::string)"Inky" );
    //Mob* Blinky=new Mob(2, (std::string)"Blinky");
    Mob* Sue=   new Mob(3, (std::string)"Sue");
    Mob* Pac=   new Mob(4, (std::string)"Pac");


    //mobiles[Pinky->getId()]= Pinky ;
    //mobiles[Inky->getId()]= Inky;
    //mobiles[Blinky->getId()]= Blinky;
    mobiles[Sue->getId()]= Sue;
    mobiles[Pac->getId()]= Pac;



    //setMobAt( Pinky->getId() , 5 ); Pinky->setPosition(1);
    //setMobAt( Inky->getId() , 10 ); Inky->setPosition(2);
    //setMobAt( Blinky->getId() , 20 ); Blinky->setPosition(3);
    setMobAt( Sue->getId() , 30 ); Sue->setPosition(4);
    setMobAt( Pac->getId() , 187 ); Pac->setPosition( 0 );

    //Pinky->setParent( this );
    //Inky->setParent( this );
    //Blinky->setParent( this );
    Sue->setParent( this );
    Pac->setParent( this );

    //Pinky->setDirection( DIRECT::N );
    //Inky->setDirection( DIRECT::W );
    //Blinky->setDirection( DIRECT::S );
    Sue->setDirection( DIRECT::E );
    Pac->setDirection( DIRECT::E );



    // dla wszystkich MOB pokaz mosty, cyklicznie przesuwaj
    //if (false ) drawBoard();

}

void Board::setMobAt( int mobId, int bridgeNum ) {  // postać zawsze na jednym akrywnym moście - o numerze unsigned int = activeBridges[ idPostaci ];
    activeBridges[mobId]=bridgeNum;
    activateBridge( activeBridges[mobId] );
    std::cout << "Board:: setMob("<< mobId << ") at: " << activeBridges[mobId];
}

void Board::moveMobTo(int mobId, DIRECT direction, int bridgeNum) {
    deactivateBridge( activeBridges[ mobId ] );
    activeBridges[ mobId ]=bridgeNum;
    activateBridge( activeBridges[ mobId ] );
}

DIRECT Board::atEdge(int id, DIRECT direction, DIRECT nextDirection) {
    //std::cout<<"Board::atEdge("<<id<<" , id: " << mobiles[id]->getPosition() <<  ");\n";


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



void Board::BoardTick() {

    for ( int i=0; i<8 ;i++ ){
        if ( mobiles[i]!= nullptr ) {
            mobiles[i]->step();
            int bridgeNum = activeBridges[i];
            //drawBridge( bridgeNum );
        }
    }


}



void Board::activateBridge(int bridgeNum) {};
void Board::deactivateBridge(int bridgeNum) {}



void Board::drawBoard() {

    Bridges b;
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
        int dot=250;
        if ( pair.second->getPower()>0 ) { dot='o'; } //249
        cdraw.WriteColourChar( (SHORT) pair.first/256 , (SHORT)pair.first%256 , dot);
    }
}