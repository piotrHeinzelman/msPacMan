//
// Created by Bill on 8/30/2023.
//

#include <iostream>
#include "Bridges.h"

#define WALL 176


/*  1   1         1         2         2         2
 *  7   8         9         0         1         2
    ░▒▓│┤╡╢╖╕╣║╗╝╜╛┐└┴┬├─┼╞╟╚╔╩╦╠═╬╧╨╤╥╙╘╒╓╫╪┘┌█▄▌▐▀
    678901234567890123456789012345678901234567890123
*/




/* No Ob. :- (
COORD COORD::operator+( const COORD & r ){
    return { static_cast<SHORT>(( X + r.X)), static_cast<SHORT>( Y + r.Y) };
} */


COORD operator +( const COORD & l , const COORD & r ){
    return { static_cast<SHORT>(( l.X + r.X)), static_cast<SHORT>( l.Y + r.Y) };
}



Bridges::Bridges(){
    bridgesData = (char*)" x x x x  xx xxx xx xx xxx xxxxx xxxxx   xxxx  xx  x  xx xx x   x  x x x  x x     x x         x x    xxxxx       xxxxx !  x x         x x     x x  x x x  x x    xxxxx x  xx xxx xx xx  xx xxx xxxx xx   xxxx xx  xx   x xx xx x x xxx x x x x             ";
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
    //DrawDot ( bridgeNum );
    //DrawMob ( bridgeNum );
}

void Bridges::DrawCenterPiontOfWall( int bridgeNum ){
    draw.WriteColourChar( getCoordOfCenterBridge ( bridgeNum ) , '+');
};     // Test use only +

void Bridges::DrawWall( int bridgeNum ){

    int edgeStart = edgeChessPosition( bridgeNum, true );
    int edgeEnd = edgeChessPosition( bridgeNum, false );

    COORD startPoint = getCoordOfEdge( edgeStart );
    COORD centerPoint = _getCheesCoordOfCenterBridge( bridgeNum );
    COORD endPoint = getCoordOfEdge( edgeEnd );


    if (isW(bridgeNum)) {
        draw.WriteColourChar(operator+(getCoordOfCenterBridge ( bridgeNum ),{-2,1}) , WALL);
        draw.WriteColourChar(operator+(getCoordOfCenterBridge ( bridgeNum ),{-1,1}) , WALL);
        draw.WriteColourChar(operator+(getCoordOfCenterBridge ( bridgeNum ),{ 0,1}) , WALL);
        draw.WriteColourChar(operator+(getCoordOfCenterBridge ( bridgeNum ),{ 1,1}) , WALL);
        draw.WriteColourChar(operator+(getCoordOfCenterBridge ( bridgeNum ),{ 2,1}) , WALL);

        draw.WriteColourChar(operator+(getCoordOfCenterBridge ( bridgeNum ),{-2,-1}) , WALL);
        draw.WriteColourChar(operator+(getCoordOfCenterBridge ( bridgeNum ),{-1,-1}) , WALL);
        draw.WriteColourChar(operator+(getCoordOfCenterBridge ( bridgeNum ),{ 0,-1}) , WALL);
        draw.WriteColourChar(operator+(getCoordOfCenterBridge ( bridgeNum ),{ 1,-1}) , WALL);
        draw.WriteColourChar(operator+(getCoordOfCenterBridge ( bridgeNum ),{ 2,-1}) , WALL);
    } else {
        draw.WriteColourChar(operator+(getCoordOfCenterBridge ( bridgeNum ),{ -1, 0}) , WALL);
        draw.WriteColourChar(operator+(getCoordOfCenterBridge ( bridgeNum ),{ 1, 0}) , WALL);
    }

    // draw edges
    drawEdge( edgeStart , startPoint );
    drawEdge( edgeEnd , endPoint );
};


void Bridges::drawEdge( int eNum , COORD point ){
    //draw.WriteColourChar(operator+(point,{ 0, 0}) , 'o');
    int ways = getAllWaysFromEdge(eNum);

    if ( (ways&1)==0 ) draw.WriteColourChar(operator+(point,{ 0, -1}) , WALL);// block N
    if ( (ways&2)==0 ) draw.WriteColourChar(operator+(point,{ -1, 0}) , WALL);// block W
    if ( (ways&4)==0 ) draw.WriteColourChar(operator+(point,{ 0,  1}) , WALL);// block S
    if ( (ways&8)==0 ) draw.WriteColourChar(operator+(point,{ 1, 0}) , WALL); // block E


    if ( (ways&1+2)==0 ) draw.WriteColourChar(operator+(point,{ -1, -1}) , WALL);// block NW
    if ( (ways&2+4)==0 ) draw.WriteColourChar(operator+(point,{ -1,  1}) , WALL);// block WS
    if ( (ways&4+8)==0 ) draw.WriteColourChar(operator+(point,{  1,  1}) , WALL);// block SE
    if ( (ways&1+8)==0 ) draw.WriteColourChar(operator+(point,{  1, -1}) , WALL);// block NE

}





void Bridges::DrawDot ( int bridgeNum ){};
void Bridges::DrawMob ( int bridgeNum ){};


