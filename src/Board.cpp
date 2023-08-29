//
// Created by John on 2023-08-27.
//

#include "Board.h"
#include <vector>
#include <iostream>
#include "Mob.h"

Board::Board() {
    // level1 - public - aby był dostępny dla testu, i można sprawdzić "naocznie" połaczenia planszy
    Bridges = " x x x x  xx xxx xx xx xxx xxxxx xxxxx   xxxx  xx  x  xx xx x   x  x x x  x x     x x         x x    xxxxx       xxxxx !  x x         x x     x x  x x x  x x    xxxxx x  xx xxx xx xx  xx xxx xxxx xx   xxxx xx  xx   x xx xx x x xxx x x x x  ";

    //std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
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

}

void Board::setMobAt( int mobId, int bridgeNum ) {  // postać zawsze na jednym akrywnym moście - o numerze unsigned int = activeBridges[ idPostaci ];
    activeBridges[mobId]=bridgeNum;
    activateBridge( activeBridges[mobId] );
    std::cout << "setMob("<< mobId << ") at: " << activeBridges[mobId];
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

void Board::activateBridge(int bridgeNum) {};
void Board::deactivateBridge(int bridgeNum) {}

void Board::drawBridge(int bridgeNum) {
    int bridgeHeight=3;
    int bridgeWidth=3;

    
    if ( bridgeNum & 1 ){ std::cout << "\n="; }
                   else { std::cout << "||"; }
}






void Board::BoardTick() {

    for ( int i=0; i<8 ;i++ ){
        if ( mobiles[i]!= nullptr ) {
              mobiles[i]->step();
              int bridgeNum = activeBridges[i];
              drawBridge( bridgeNum );
        }
    }


}


/*  1   1         1         2         2         2
 *  7   8         9         0         1         2
    ░▒▓│┤╡╢╖╕╣║╗╝╜╛┐└┴┬├─┼╞╟╚╔╩╦╠═╬╧╨╤╥╙╘╒╓╫╪┘┌█▄▌▐▀
    678901234567890123456789012345678901234567890123



*/


void Board::drawBoard() {
#define BOARD_WIDTH 19
#define BOARD_HEIGHT 22

#define WID_MULL 4
#define HEI_MULL 2

    for ( int i=0; i<BOARD_WIDTH*WID_MULL+2; i++ ){
        //cdraw.WriteColourChar(0,i,)
    }



}