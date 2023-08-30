//
// Created by Bill on 8/30/2023.
//

#include "Bridges.h"






int getStartDirections( int number );
int getEndDirections  ( int number );

int getNextNumber( int endEdge , DIRECT goFrom , DIRECT goTo ){
  return 1;
};

Bridges::Bridges(){
    bridgesData = " x x x x  xx xxx xx xx xxx xxxxx xxxxx   xxxx  xx  x  xx xx x   x  x x x  x x     x x         x x    xxxxx       xxxxx !  x x         x x     x x  x x x  x x    xxxxx x  xx xxx xx xx  xx xxx xxxx xx   xxxx xx  xx   x xx xx x x xxx x x x x  ";
}

bool Bridges::isExsits( int number ){
    return bridgesData[number]!=' ';
}

bool Bridges::isW(int number){
    return (number&0x01)==1;
}

int Bridges::edgePosition( int number, bool fromStart ){
    // TESTED !!
    bool isW_ = isW( number );
    int n=number;
    return isW_ ? ( fromStart ? n-1 : n+1 ) : ( fromStart ? n-10 : n+10 ) ;
};




int Bridges::hasWay( int bridgePosition, DIRECT direction, bool fromStart ){
    bool isW_=isW(bridgePosition);
    int edgePosition = fromStart ? ( isW_ ? bridgePosition-1 : bridgePosition-10 ) : ( isW_ ? bridgePosition+1 : bridgePosition+10 ) ;

};

bool hasWayFromEnd( int number, DIRECT direction ){
    return true;
}