//
// Created by Bill on 8/30/2023.
//

#include <iostream>
#include <cassert>
#include "CppTests.h"
#include "../src/Dot.h"
#include <windows.h>
#include <unistd.h>


void showPoint( COORD point ){
    std::cout << "x: " << point.X << ", y:" + point.Y << "\n";
}

std::ostream & operator <<( std::ostream & os, const COORD & point )
{
    os << "x: " << point.X << ",y: " << point.Y;
    return os;
}

bool operator==( const COORD & l , const COORD & r ){
    return ( l.X==r.X && l.Y==r.Y );
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

    assert(0 == b.edgeChessPosition(1, true));

    assert(2 == b.edgeChessPosition(1, false));

    assert(20 == b.edgeChessPosition(30, true));
    assert(40 == b.edgeChessPosition(30, false));





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


/*  TEST chessCoordToScreenCoord
    COORD in = {0,0};
    COORD req = {1,0};
    COORD out = b._getScreenCoordofCheesCoord( in );
    std::cout << "in: "<< in << " out: " << out << ", red:" << req << "\n";
*/

// TEST _getScreenCoordofCheesCoord                                                        //   0123        01234567
    assert(b._getScreenCoordofCheesCoord({0, 0}) == ( COORD{1, 0} )); //   o...   ->   [o]....
    assert(b._getScreenCoordofCheesCoord({1, 0}) == ( COORD{4, 0} )); //   .o..   ->   [ ][o]..
    assert(b._getScreenCoordofCheesCoord({2, 0}) == ( COORD{7, 0} )); //   ..o.   ->   [ ][ ][o]
    assert(b._getScreenCoordofCheesCoord({0, 3}) == ( COORD{1, 3} )); //   ..o.   ->   [ ][ ][o]
    assert(b._getScreenCoordofCheesCoord({2, 23}) == ( COORD{7, 23} )); //   ..o.   ->   [ ][ ][o]

// TEST _getCheesCoordOfCenterBridge
/*    int in = 192;
    COORD req = {0,1};
    COORD out = b._getCheesCoordOfCenterBridge( in );
    std::cout << "in: "<< in << " out: " << out << ", red:" << req << "\n";
*/
    assert(b._getCheesCoordOfCenterBridge(1) == ( COORD{1, 0} )); // o-o
    assert(b._getCheesCoordOfCenterBridge(3) == ( COORD{3, 0} )); // o-o
    assert(b._getCheesCoordOfCenterBridge(23) == ( COORD{3, 2} ));// o-o
    assert(b._getCheesCoordOfCenterBridge(237) == ( COORD{17, 22} ));// o-o

    assert(b._getCheesCoordOfCenterBridge(10) == ( COORD{0, 1} )); // o
    assert(b._getCheesCoordOfCenterBridge(14) == ( COORD{4, 1} )); // |
    assert(b._getCheesCoordOfCenterBridge(28) == ( COORD{18, 1} ));// o

    assert(b._getCheesCoordOfCenterBridge(192) == ( COORD{2, 19} ));
    assert(b._getCheesCoordOfCenterBridge(210) == ( COORD{0, 21} ));



// TEST getCoordOfCenterBridge( int bridgeNum )
 /*
    int  i=237;
    COORD req = {10,0};
    std::cout << "i: "<< i << ", " << b.getCoordOfCenterBridge( i ) << "   oczekiwana: " << req << "\n";
 */
    assert(b.getCoordOfCenterBridge(1 ) == ( COORD{4, 0} ));
    assert(b.getCoordOfCenterBridge(3 ) == ( COORD{10, 0} ));
    assert(b.getCoordOfCenterBridge(17 ) == ( COORD{52, 0} ));

    assert(b.getCoordOfCenterBridge(237 ) == ( COORD{52, 22} ));


// TEST getCoordOfEdge  Chees Coord !!!

//    int  i=20; std::cout << "i: "<< i << ", " << b.getCoordOfEdge( i ) << "\n\n";
/*    assert(b.getCoordOfEdge(0 ) == ( COORD{0, 0} ));
    assert(b.getCoordOfEdge(2 ) == ( COORD{2, 0} ));
    assert(b.getCoordOfEdge(18 ) == ( COORD{18, 0} ));
    assert(b.getCoordOfEdge(20 ) == ( COORD{0, 2} ));
    assert(b.getCoordOfEdge(22) == ( COORD{2, 2} ));
    assert(b.getCoordOfEdge(234) == ( COORD{14, 22} ));
    assert(b.getCoordOfEdge(238) == ( COORD{18, 22} ));
*/

// TEST getCoordOfEdge (int bridgeNum, bool fromStart );
//int  i=238; std::cout<<"i: "<<i<< ", "<< b.getCoordOfEdge( i )<<"\n";

    assert(b.getCoordOfEdge(0 ) == ( COORD{1, 0} ));
    assert(b.getCoordOfEdge(2 ) == ( COORD{7, 0} ));
    assert(b.getCoordOfEdge(238 ) == ( COORD{55, 22} ));

    {   // TEST Dot manipulation

        Board bo;
        std::map< int , Dot* > dots;
        Dot* dot = new Dot( 1, {2,3} ) ;
        dots[3] = dot;
        assert( dot == dots[3] );

        Dot* myDot = bo.createDot( 1 , {4,0} , true );
        assert(myDot == bo.getDotFrom({4,0} ) );
        assert(true == bo.IsDotAt({4,0} ) );
        assert(false == bo.IsDotAt({3,0} ) );


        std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    //    b.DrawWall( 1 );
    //    b.DrawWall( 17 );
    //    b.DrawWall( 221 );
    //    b.DrawWall( 237 );

        bo.createDot(1 , { 2,0 } , true , 50 , 1000 );
        bo.createDot(17 , { 54,0 } , true , 50 , 1000 );
        bo.createDot(221 , { 2,22 } , true , 50 , 1000 );
        bo.createDot(237 , { 54,22 } , true , 50 , 1000 );

        for (int i = 0; i < 240; i++) {  // walls
            if ( !b.isExsits( i ) ) { continue; }
            COORD center = b.getCoordOfCenterBridge( i );
            bo.createDot( i , center , b.isW( i ));
            //b.DrawWall( i );
        }
        //bo.drawAllDots();




        Mob* minion = new Mob(4, (std::string)"Minion");
        bo.eatDot( minion, {1,1} );
        assert(1 == minion->getPoints());
        assert(0 == minion->getPower());
        //std::cout<<"Minion: power: " << minion->getPower() << ", points: " << minion->getPoints()<< "\n";
        bo.eatDot( minion , {2,0} );
        assert(51 == minion->getPoints());
        assert(1000 == minion->getPower());
        //std::cout<<"Minion: power: " << minion->getPower() << ", points: " << minion->getPoints()<< "\n";

        //b.draw.WriteColourChar( {0,0 } , 'X' );


        bo.drawDotsOfBridge( 1 );
        bo.drawDotsOfBridge( 3 );
        bo.drawDotsOfBridge( 10 );

        b.DrawWall( 1 );
        b.DrawWall( 3 );
        b.DrawWall( 10 );

        Mob* john = new Mob(4, (std::string)"John");






        bo.setMobAt( minion->getId(), 1 );

        while(true) {
            minion->setDirection(DIRECT::E);
            for (int i = 0; i < 10; i++) {
                bo.moveAllMobs();
                sleep(1);
                bo.redrawAllBridge();
                bo.drawAllMob();
            }
            minion->setDirection(DIRECT::W);
            for (int i = 0; i < 10; i++) {
                bo.moveAllMobs();
                sleep(1);
                bo.redrawAllBridge();
                bo.drawAllMob();
            }
        }

    }




}

