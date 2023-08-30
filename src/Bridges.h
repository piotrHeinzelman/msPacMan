//
// Created by Bill on 8/30/2023.
//

#ifndef MSPACMAN_BRIDGES_H
#define MSPACMAN_BRIDGES_H

#include <set>
#include "DIRECT.h"
#include "../tests/CppTests.h"


/*
    Most ma pocztarek (lewy koniec, lub górny koniec)
    oraz kres ( prawy lub dolny )

 */

class Bridges {

friend class CppTests;

private:
    // level 1
    char* bridgesData = nullptr;// = " x x x x  xx xxx xx xx xxx xxxxx xxxxx   xxxx  xx  x  xx xx x   x  x x x  x x     x x         x x    xxxxx       xxxxx !  x x         x x     x x  x x x  x x    xxxxx x  xx xxx xx xx  xx xxx xxxx xx   xxxx xx  xx   x xx xx x x xxx x x x x  ";

    //std::set<DIRECT> getStartWay( int number );
    //std::set<DIRECT> getEndWay( int number );
public:
    explicit Bridges();

    bool isExsits( int number );
    bool isW(int number);
    int edgePosition( int Number, bool fromStart );

    int hasWay( int number, DIRECT direction, bool fromStart );

    std::set<DIRECT> getWays( int number , bool fromStart );

    int getNextNumber( int endEdge , DIRECT goFrom , DIRECT goTo );


};


#endif //MSPACMAN_BRIDGES_H
