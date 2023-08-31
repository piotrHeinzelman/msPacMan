//
// Created by Bill on 8/30/2023.
//

#include <iostream>
#include "Bridges.h"


/*  1   1         1         2         2         2
 *  7   8         9         0         1         2
    ░▒▓│┤╡╢╖╕╣║╗╝╜╛┐└┴┬├─┼╞╟╚╔╩╦╠═╬╧╨╤╥╙╘╒╓╫╪┘┌█▄▌▐▀
    678901234567890123456789012345678901234567890123
*/

Bridges::Bridges(){
    bridgesData = (char*)" x x x x  xx xxx xx xx xxx xxxxx xxxxx   xxxx  xx  x  xx xx x   x  x x x  x x     x x         x x    xxxxx       xxxxx !  x x         x x     x x  x x x  x x    xxxxx x  xx xxx xx xx  xx xxx xxxx xx   xxxx xx  xx   x xx xx x x xxx x x x x  ";
}


int Bridges::checkI(int bridgeNum ){
    if (bridgeNum < 0)   return 0;
    if (bridgeNum > 238) return 246;
    return bridgeNum;
}


bool Bridges::isExsits( int bridgeNum ){ //TESTED
    bridgeNum = checkI( bridgeNum );
    return bridgesData[ bridgeNum ]!=' ';
}


bool Bridges::isW(int bridgeNum){ // TESTED
    return (bridgeNum & 0x01)==1;
}


int Bridges::edgeChessPosition( int bridgeNum, bool fromStart ){  // TESTED
    bool isW_ = isW( bridgeNum );
    if ( isW_ ) return fromStart ? bridgeNum+W/2 : bridgeNum+E/2 ;
    return             fromStart ? bridgeNum+N/2 : bridgeNum+S/2 ;
};


COORD Bridges::getCoordOfEdge( int eNum ){ // TESTED
    SHORT x;
    SHORT y;
        x=eNum%20;  y=2*(eNum/20);
    //return  {x,y};
    return _getScreenCoordofCheesCoord({x,y});
};


bool Bridges::isExistsWayFromEdge( int edge, DIRECT direction ){ //TESTED
    return  isExsits( edge+(direction/2));
}


int Bridges::getWayFromEdge(int eNum, DIRECT direction ){// TESTED
    if (isExistsWayFromEdge(eNum , direction )) {
        return eNum + (direction / 2);
    }
    throw std::runtime_error("Bridges::getWayFromEdge -> nie ma takiego pola");
    return -1;
}


int Bridges::getAllWaysFromEdge( int eNum ){ // tested
    int ways=0;
        if (isExistsWayFromEdge(eNum, N )){ ways+=1;  }
        if (isExistsWayFromEdge(eNum, W )){ ways+=2;  }
        if (isExistsWayFromEdge(eNum, S )){ ways+=4;  }
        if (isExistsWayFromEdge(eNum, E )){ ways+=8;  }
    return ways;
}


// ****************** WORKING HERE !!!

COORD Bridges::_getScreenCoordofCheesCoord(const COORD & chess ){ // TESTED
    return COORD{ static_cast<SHORT>(  1+(chess.X*3) ) , chess.Y };
}

COORD Bridges::_getCheesCoordOfCenterBridge(int i ){
    SHORT x;
    SHORT y;
    if ( isW (i)) {
        x=i%20;  y=(i-x)/10;
    } else {
        x=(i-10)%20;  y=1+2*((i-10)/20);
    }
    return { x,y };
}

COORD Bridges::getCoordOfCenterBridge( int bridgeNum ){
    return _getScreenCoordofCheesCoord(_getCheesCoordOfCenterBridge(bridgeNum));
}















void Bridges::drawBridge(int bridgeNum) {
    DrawWall( bridgeNum );
    DrawDot ( bridgeNum );
    DrawMob ( bridgeNum );
}

void Bridges::DrawCenterPiontOfWall( int bridgeNum ){
    draw.WriteColourChar( getCoordOfCenterBridge ( bridgeNum ) , '+');
    // and draw edges
    if ( !isW(bridgeNum) ) return;
    int edgeStart = edgeChessPosition( bridgeNum, true );
    int edgeEnd = edgeChessPosition( bridgeNum, false );
    draw.WriteColourChar( getCoordOfEdge ( edgeStart ) , 'c');
    draw.WriteColourChar( getCoordOfEdge ( edgeEnd ) , 'o');

};     // Test use only +

void Bridges::drawBridgeW( int bridgeNum ) {}
void Bridges::drawBridgeH( int bridgeNum ) {}

void Bridges::DrawWall( int bridgeNum ){};
void Bridges::DrawDot ( int bridgeNum ){};
void Bridges::DrawMob ( int bridgeNum ){

    /*
     // dots
     draw.WriteColourChar( x-3,y,248 );
     draw.WriteColourChar( x-1,y,248 );
     draw.WriteColourChar( x+1,y,248 );
     draw.WriteColourChar( x+3,y,248 );

     draw.WriteColourChar( x,y,196 );

     int start = edgePosition( bridgeNum , true );
     int end = edgePosition( bridgeNum , false );
     int startWays = getAllWaysFromEdge( start );
     int endWays   = getAllWaysFromEdge( end );

     if (( startWays|( 1+2 ))==0) { drawTopLeftConner( start ); }
 */

    //cdraw.WriteColourChar( x+CELL_WIDTH*3,y,196 );

    //for (int i=-CELL_WIDTH+1;i<CELL_WIDTH*3-1;i++){
    //    cdraw.WriteColourChar( x+i,y,196 );
    //}

    //cdraw.WriteColourChar( x-CELL_WIDTH,y,250 );
    //cdraw.WriteColourChar( x+CELL_WIDTH+CELL_WIDTH-1,y,250 );



    // if (Bridges[bridgeNum+2]==' '){ cdraw.WriteColourChar( x+5,y,176 );  }
    // if (Bridges[bridgeNum-2]==' '){ cdraw.WriteColourChar( x-3,y,176 );  }

};











void Bridges::drawBoard() {
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    if ( !false ) { // wyłaczone rysowanie planszy
        for (int i = 0; i < 240; i++) {  // walls
            if ( !isExsits( i ) ) { continue; }
                // draw
                 DrawCenterPiontOfWall( i ); // testing only
                 DrawWall( i );

        }

        for (int i = 0; i < 240; i++) { // dots
            if ( !isExsits( i ) ) { continue; }
                //draw
                DrawDot( i );
        }
    }
}






