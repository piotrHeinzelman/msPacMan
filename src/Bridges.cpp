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
    for(int i=1;i<255;i++) {
        if ( bridgesData[i] != ' ' ) {
                addBridge(i ); // add Wbridge
            }
        }
    for(int i=1;i<255;i++) {
        if ( bridgeAry[i]!=nullptr) {
            Bridge* bridge=bridgeAry[i];
            int startEdge = bridge->getStartEdge();
            int endEdge = bridge->getEndEdge();

            Ways w = getWays( startEdge ) ;
            bridge->setStartWays( w );
                 w = getWays( endEdge ) ;
            bridge->setEndWays( w );
 //           std::cout << "\nN:" << w.n << " : " << bridge->getEndWays().n << "\n";
        }
    }
}


Ways Bridges::getWays( int edge ) {
    Ways w;
    if ( bridgesData[edge-1]=='x') {  w.w = bridgeAry[ edge-1 ]; } else   { w.w=nullptr; }
    if ( bridgesData[edge+1]=='x') {  w.e = bridgeAry[ edge+1 ]; } else   { w.e=nullptr; }
    if ( bridgesData[edge-10]=='x') { w.n = bridgeAry[ edge-10 ]; } else { w.n=nullptr; }
    if ( bridgesData[edge+10]=='x') { w.s = bridgeAry[ edge+10 ]; } else { w.s=nullptr; }
 //   std::cout << "\nN:" << w.n <<"\n";
//   std::cout << "\ns:" << w.s <<"\n";
  //  std::cout << "\nw:" << w.w <<"\n";
//    std::cout << "\ne:" << w.e <<"\n";
    return w;
}


Bridge * Bridges::getBridgeByInt(int bridgeNum) {
    return bridgeAry[bridgeNum];
}

void Bridges::addBridge( int bridgeNum ) {
    bridgeAry[bridgeNum] = new Bridge( bridgeNum );
};











int Bridges::checkI(int bridgeNum ){
    if (bridgeNum < 0)   return 0;
    if (bridgeNum > 238) return 246;
    return bridgeNum;
}


bool Bridges::isExsits( int bridgeNum ){ //TESTED
    bridgeNum = checkI( bridgeNum );
    return bridgeAry[ bridgeNum ]!=nullptr;
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

/*
bool Bridges::isExistsWayFromEdge( int edge, DIRECT direction ){ //TESTED
    return  isExsits( edge+(direction/2));
}
*/
/*
int Bridges::getWayFromEdge(int eNum, DIRECT direction ){// TESTED
    return getBridgeByInt( eNum ).

    if (isExistsWayFromEdge(eNum , direction )) {
        return eNum + (direction / 2);
    }
    throw std::runtime_error("Bridges::getWayFromEdge -> nie ma takiego pola");
    return -1;
}
*/
/*
std::set<DIRECT>  Bridges::getAllWaysFromEdge( int eNum ){ // tested
    std::set<DIRECT> ways;
        if (isExistsWayFromEdge(eNum, N )){ ways.insert( DIRECT::N );  }
        if (isExistsWayFromEdge(eNum, W )){ ways.insert( DIRECT::W );  }
        if (isExistsWayFromEdge(eNum, S )){ ways.insert( DIRECT::S );  }
        if (isExistsWayFromEdge(eNum, E )){ ways.insert( DIRECT::E );  }
    return ways;
}
*/

// ****************** WORKING HERE !!!

COORD Bridges::_getScreenCoordofCheesCoord(const COORD & chess ){ // TESTED
    return COORD{ static_cast<SHORT>(  1+(chess.X*3) ) , chess.Y };
}

COORD Bridges::_getCheesCoordOfCenterBridge(int i ){
    SHORT x; SHORT y;
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


void Bridges::drawBridge( Bridge* bridge ) {
    DrawWall(bridge);
    drawEdge(bridge,true);
    drawEdge(bridge,false);
    DrawDot(bridge);
    DrawMob(bridge);
}



void Bridges::DrawCenterPiontOfWall( Bridge* bridge ){
    draw.WriteColourChar( bridge->getCenterPoint() , '+');
};







void Bridges::DrawWall( Bridge* bridge ){

    COORD center = bridge->getCenterPoint();
    if ( bridge->isW()){
        draw.WriteColourChar(operator+(center,{-2,1}) , WALL);
        draw.WriteColourChar(operator+(center,{-1,1}) , WALL);
        draw.WriteColourChar(operator+(center,{ 0,1}) , WALL);
        draw.WriteColourChar(operator+(center,{ 1,1}) , WALL);
        draw.WriteColourChar(operator+(center,{ 2,1}) , WALL);

        draw.WriteColourChar(operator+(center,{-2,-1}) , WALL);
        draw.WriteColourChar(operator+(center,{-1,-1}) , WALL);
        draw.WriteColourChar(operator+(center,{ 0,-1}) , WALL);
        draw.WriteColourChar(operator+(center,{ 1,-1}) , WALL);
        draw.WriteColourChar(operator+(center,{ 2,-1}) , WALL);
    } else {
        draw.WriteColourChar(operator+(center,{ -1, 0}) , WALL);
        draw.WriteColourChar(operator+(center,{ 1, 0}) , WALL);
    }

    // draw edges
    drawEdge( bridge , true  );
    drawEdge( bridge , false  );

}

void Bridges::drawEdge( Bridge* bridge, bool isStart ){

    Ways ways=isStart ? bridge->getStartWays() : bridge->getEndWays();
    COORD point = isStart ? bridge->getStartPoint() : bridge->getEndPoint();

    if ( ways.n==nullptr )  draw.WriteColourChar(operator+(point,{ 0, -1}) , WALL);// block N
    if ( ways.w==nullptr )  draw.WriteColourChar(operator+(point,{ -1, 0}) , WALL);// block W
    if ( ways.s==nullptr )  draw.WriteColourChar(operator+(point,{ 0,  1}) , WALL);// block S
    if ( ways.e==nullptr )  draw.WriteColourChar(operator+(point,{ 1, 0}) , WALL); // block E


    if ( ways.n ==nullptr   && ways.w ==nullptr )   draw.WriteColourChar(operator+(point,{ -1, -1}) , WALL);// block NW
    if ( ways.w ==nullptr   && ways.s ==nullptr )   draw.WriteColourChar(operator+(point,{ -1,  1}) , WALL);// block WS
    if ( ways.s ==nullptr   && ways.e ==nullptr )   draw.WriteColourChar(operator+(point,{  1,  1}) , WALL);// block SE
    if ( ways.n ==nullptr   && ways.e ==nullptr )   draw.WriteColourChar(operator+(point,{  1, -1}) , WALL);// block NE
}


void Bridges::DrawDot ( Bridge* bridge ){};
void Bridges::DrawMob ( Bridge* bridge ){}

void Bridges::drawAllBridges() {
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    for ( int i=1;i<=250;i++) {
        Bridge* b = bridgeAry[i];
        if ( b!= nullptr ) {
            drawBridge( b );
        }
    }
}



