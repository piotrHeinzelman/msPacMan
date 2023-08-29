//
// Created by John on 2023-08-27.
//

#include "Board.h"
#include <vector>
#include "Mob.h"

Board::Board() {
    // level1 - public - aby był dostępny dla testu, i można sprawdzić "naocznie" połaczenia planszy
    Bridges = " x x x x  xx xxx xx xx xxx xxxxx xxxxx   xxxx  xx  x  xx xx x   x  x x x  x x     x x         x x    xxxxx       xxxxx !  x x         x x     x x  x x x  x x    xxxxx x  xx xxx xx xx  xx xxx xxxx xx   xxxx xx  xx   x xx xx x x xxx x x x x  ";

}

void Board::prepare() {
    Mob* Pinky= new Mob(0, (std::string) "Pinky" );
    Mob* Inky=  new Mob(1, (std::string)"Inky" );
    Mob* Blinky=new Mob(2, (std::string)"Blinky");
    Mob* Sue=   new Mob(3, (std::string)"Sue");
    Mob* Pac=   new Mob(4, (std::string)"Pac");


    mobiles[Pinky->getId()]= Pinky ;
    mobiles[Inky->getId()]= Inky;
    mobiles[Blinky->getId()]= Blinky;
    mobiles[Sue->getId()]= Sue;
    mobiles[Pac->getId()]= Pac;



    setMobAt( Pac->getId() , 187 );

    Pac->setPosition( 0 );
    Pac->setDirection( E );

    // dla wszystkich MOB pokaz mosty, cyklicznie przesuwaj

}

void Board::setMobAt(int i, int bridgeNum) {  // postać zawsze na jednym akrywnym moście - o numerze unsigned int = activeBridges[ idPostaci ];
    activeBridges[i]=bridgeNum;
    activateBridge( activeBridges[i] );
}

void Board::moveMobTo(int mobId, int bridgeNum) {
    deactivateBridge( activeBridges[ mobId ] );
    activeBridges[ mobId ]=bridgeNum;
    activateBridge( activeBridges[ mobId ] );

}

DIRECT Board::atEdge(int id, DIRECT direction, DIRECT nextDirection) {
    int ActualPosition=activeBridges[id];
    int next = ActualPosition+direction;
    if ( next > 0 && next < 255 && activeBridges[next]==' '){
        // nastepny most nie istnieje
        next = ActualPosition+nextDirection;
        if ( next > 0 && next < 255 && activeBridges[next]==' '){ ((Mob*)mobiles[id])->setDirection( STOP ); }
    }
}

void Board::activateBridge(int bridgeNum) {};
void Board::deactivateBridge(int bridgeNum) {}