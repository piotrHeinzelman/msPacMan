//
// Created by Bill on 8/30/2023.
//

#include <iostream>
#include <cassert>
#include "CppTests.h"
#include <windows.h>


void showPoint( COORD point ){
    std::cout << "x: " << point.X << ", y:" + point.Y << "\n";
}

std::ostream & operator <<( std::ostream & os, const COORD & point )
{
    os << "x: " << point.X << ",y: " << point.Y;
    return os;
}


void CppTests::BridgesTest() {

    //std::cout << "before tests\n";
    Bridges b;

    assert(2 + 2 == 4);
    assert(false == b.isExsits(0));

    assert(true == b.isExsits(1));
    assert(false == b.isExsits(2));
    assert(true == b.isExsits(10));

    assert(true == b.isW(1));
    assert(false == b.isW(10));

    assert(0 == b.edgePosition(1, true));

    assert(2 == b.edgePosition(1, false));

    assert(20 == b.edgePosition(30, true));
    assert(40 == b.edgePosition(30, false));



    assert(true == b.isExistsWayFromEdge(144, N));
    assert(false == b.isExistsWayFromEdge(144, E));
    assert(true == b.isExistsWayFromEdge(144, S));
    assert(false == b.isExistsWayFromEdge(144, W));
    assert(true == b.isExistsWayFromEdge(0, E));
    assert(true == b.isExistsWayFromEdge(0, S));
    assert(true == b.isExistsWayFromEdge(238, N));
    assert(true == b.isExistsWayFromEdge(236, W));
    assert(false == b.isExistsWayFromEdge(170, W));
    assert(true == b.isExistsWayFromEdge(170, E));


    assert(1 == b.getWayFromEdge(0, E));
    assert(10 == b.getWayFromEdge(0, S));
    assert(202 == b.getWayFromEdge(212, N));
    assert(185 == b.getWayFromEdge(186, W));

    assert(1+2+8 == b.getAllWaysFromEdge(216));
    assert(4+8 == b.getAllWaysFromEdge(0));
    assert(1+4 == b.getAllWaysFromEdge(154));







int  i=1;
std::cout << "i: "<< i << ", " << b.getCoordOfCenterBridge( i ) << "\n";

/*
    // Operatory
    Int & operator =( const Int & x )
    {
        i = x.i;
        return * this;
    }
*/


/*
   // assert(1+4 == b.getCoordOfEdge(0));
   //  Bridges::getCoordOfEdge( int edge );
ConsoleDraw draw;
int ed=0;    std::cout << ed << "::  ,x: " << b.getCoordOfEdge(ed).X << ", y:" << b.getCoordOfEdge(ed).Y << "\n"; draw.WriteColourChar( b.getCoordOfEdge(ed), 'A' );
    ed=2;    std::cout << ed << "::  ,x: " << b.getCoordOfEdge(ed).X << ", y:" << b.getCoordOfEdge(ed).Y << "\n"; draw.WriteColourChar( b.getCoordOfEdge(ed), 'B' );
    ed=4;    std::cout << ed << "::  ,x: " << b.getCoordOfEdge(ed).X << ", y:" << b.getCoordOfEdge(ed).Y << "\n"; draw.WriteColourChar( b.getCoordOfEdge(ed), 'C' );
    ed=10;    std::cout << ed << "::  ,x: " << b.getCoordOfEdge(ed).X << ", y:" << b.getCoordOfEdge(ed).Y << "\n"; draw.WriteColourChar( b.getCoordOfEdge(ed), 'D' );
    ed=18;    std::cout << ed << "::  ,x: " << b.getCoordOfEdge(ed).X << ", y:" << b.getCoordOfEdge(ed).Y << "\n"; draw.WriteColourChar( b.getCoordOfEdge(ed), 'E' );
    ed=20;    std::cout << ed << "::  ,x: " << b.getCoordOfEdge(ed).X << ", y:" << b.getCoordOfEdge(ed).Y << "\n"; draw.WriteColourChar( b.getCoordOfEdge(ed), 'F' );
    ed=40;    std::cout << ed << "::  ,x: " << b.getCoordOfEdge(ed).X << ", y:" << b.getCoordOfEdge(ed).Y << "\n"; draw.WriteColourChar( b.getCoordOfEdge(ed), 'G' );
    ed=200;    std::cout << ed << "::  ,x: " << b.getCoordOfEdge(ed).X << ", y:" << b.getCoordOfEdge(ed).Y << "\n"; draw.WriteColourChar( b.getCoordOfEdge(ed), 'H' );
    ed=210;    std::cout << ed << "::  ,x: " << b.getCoordOfEdge(ed).X << ", y:" << b.getCoordOfEdge(ed).Y << "\n"; draw.WriteColourChar( b.getCoordOfEdge(ed), 'I' );
    ed=220;    std::cout << ed << "::  ,x: " << b.getCoordOfEdge(ed).X << ", y:" << b.getCoordOfEdge(ed).Y << "\n\n"; draw.WriteColourChar( b.getCoordOfEdge(ed), 'J' );
           //b.drawBridge(1);

    exit(1);
}

/* IS NOT TEST
std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    ConsoleDraw draw;
    int ed=1;    std::cout << ed << "::  ,x: " << b.getCoordOfEdge(ed).X << ", y:" << b.getCoordOfEdge(ed).Y << "\n"; draw.WriteColourChar( b.getCoordOfEdge(ed), 'A' );
    ed=17;    std::cout << ed << "::  ,x: " << b.getCoordOfEdge(ed).X << ", y:" << b.getCoordOfEdge(ed).Y << "\n"; draw.WriteColourChar( b.getCoordOfEdge(ed), 'B' );
    ed=237;    std::cout << ed << "::  ,x: " << b.getCoordOfEdge(ed).X << ", y:" << b.getCoordOfEdge(ed).Y << "\n"; draw.WriteColourChar( b.getCoordOfEdge(ed), 'C' );
*/

//    b.drawBridge(20);

}

