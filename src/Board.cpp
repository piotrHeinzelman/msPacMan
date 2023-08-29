//
// Created by John on 2023-08-27.
//

#include "Board.h"
#include <vector>
#include <iostream>
#include <unistd.h>
#include "Mob.h"

Board::Board() {
    // level1 - public - aby był dostępny dla testu, i można sprawdzić "naocznie" połaczenia planszy
    Bridges = " x x x x  xx xxx xx xx xxx xxxxx xxxxx   xxxx  xx  x  xx xx x   x  x x x  x x     x x         x x    xxxxx       xxxxx !  x x         x x     x x  x x x  x x    xxxxx x  xx xxx xx xx  xx xxx xxxx xx   xxxx xx  xx   x xx xx x x xxx x x x x  ";

    std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
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
    drawBoard();
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
    if ( bridgeNum & 1 ) return drawBridgeW( bridgeNum );
                   else  return drawBridgeH( bridgeNum );
}

void Board::drawBridgeW(int bridgeNum) {
    SHORT x=bridgeNum%20;
    SHORT y=((bridgeNum-x)/20)*2;

    x*=CELL_WIDTH;
    y*=CELL_HEIGHT;
    //cdraw.WriteColourChar( x,y,196 );


    //cdraw.WriteColourChar( x+CELL_WIDTH*3,y,196 );

    //for (int i=-CELL_WIDTH+1;i<CELL_WIDTH*3-1;i++){
    //    cdraw.WriteColourChar( x+i,y,196 );
    //}

    //cdraw.WriteColourChar( x-CELL_WIDTH,y,250 );
    //cdraw.WriteColourChar( x+CELL_WIDTH+CELL_WIDTH-1,y,250 );

    cdraw.WriteColourChar( x-2,y,248 );
    cdraw.WriteColourChar( x,y,248 );
    cdraw.WriteColourChar( x+2,y,248 );
    cdraw.WriteColourChar( x+4,y,248 );

   // if (Bridges[bridgeNum+2]==' '){ cdraw.WriteColourChar( x+5,y,176 );  }
   // if (Bridges[bridgeNum-2]==' '){ cdraw.WriteColourChar( x-3,y,176 );  }

}

void Board::drawBridgeH( int bridgeNum ) {

    SHORT y=1+2*((bridgeNum-10)/20) ;
    SHORT x=(bridgeNum-10)%20;

    x*=CELL_WIDTH;
    y*=CELL_HEIGHT;
    //cdraw.WriteColourChar( x,y,179 );

    //cdraw.WriteColourChar( x+1,y-1,250 );
    //cdraw.WriteColourChar( x+1,y+1,250 );

    cdraw.WriteColourChar( x+1,  y,248 );

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

    //drawBridgeH(10);
    drawBridgeH(1);

    if (!false) { // wyłaczone rysowanie planszy
    for (int i = 0; i < 240; i++, i++) {
        if (this->Bridges[i] != ' ') { drawBridgeH(i); }
        if (this->Bridges[i + 1] != ' ') { drawBridgeW(i + 1); }
    }
    }
    if (true )return;
    cdraw.WriteColourChar(0,0,210);
    cdraw.WriteColourChar(2+BW, 0 ,183);
    cdraw.WriteColourChar(0,    2+BH,211);
    cdraw.WriteColourChar(2+BW, 2+BH , 189);
    for ( int i=0; i<=BW; i++ ){
         cdraw.WriteColourChar(1+i,0,196);
         cdraw.WriteColourChar(1+i,2+BH ,196);
    }
    for ( int i=0; i<=BH; i++ ){
        cdraw.WriteColourChar(0    ,1+i,186);
        cdraw.WriteColourChar(2+BW , i+1, 186);
    }




}