//
// Created by Bill on 8/30/2023.
//

#ifndef MSPACMAN_BRIDGES_H
#define MSPACMAN_BRIDGES_H


#define BOARD_WIDTH 19
#define BOARD_HEIGHT 23

#define CELL_WIDTH 3 //6
#define CELL_HEIGHT 1 // 2

#define BH BOARD_HEIGHT*CELL_HEIGHT
#define BW BOARD_WIDTH*CELL_WIDTH

#define popW 0
#define popH 0

#include <set>
#include <map>
#include "DIRECT.h"
#include "../tests/CppTests.h"
#include "ConsoleDraw.h"
#include "Bridge.h"
#include "Ways.h"


/*
    Most ma pocztarek (lewy koniec, lub górny koniec)
    oraz kres ( prawy lub dolny )

 */

class Bridges {

friend class CppTests;

private:
    char* bridgesData = nullptr;  // Bridges` data place
    Bridge* bridgeAry[256]={nullptr};
    ConsoleDraw draw;             // drawing class

public:
    explicit Bridges();           // construct object, set bridgesData
    void addBridge( int bridgeNum );
    Ways getWays( int bridgeNum );


    int checkI( int bridgeNum );     // guard array limit ( bridgeNum<0 =0 ,  >MAX ==MAX );
    bool isExsits( int bridgeNum );  // is Exists Brigde ? // is data[i]!=" "
    bool isW(int bridgeNum);         // is Horizontal bridge ? / or vertical
    COORD getCoordOfEdge( int eNum );// get x,y screen position od Edge ( end of Bridge )

    int edgeChessPosition   ( int bridgeNum, bool fromStart ); // getEdgeNum like Data[] od Bridge. Start is Top or Left Edge, !Start is Bottom or Right edge.
   // bool isExistsWayFromEdge( int eNum, DIRECT direction );  // is exists way to direction from edge ?
   // int getWayFromEdge      ( int eNum, DIRECT direction );  // get new Bridge num from edge to direction
                                                //                                                            8 4 2 1
   // std::set<DIRECT> getAllWaysFromEdge( int eNum );       // get all possible direction from edge, binary code is: 0b00 E S W N


    void drawAllBridges();
    void drawBridge ( Bridge* bridge  );

    void DrawWall( Bridge* bridge );      // TODO

    void DrawCenterPiontOfWall( Bridge* bridge );  //TODO

    void DrawDot ( Bridge* bridge );        // TODO
    void DrawMob ( Bridge* bridge );        // TODO
            // Test use only +

    void drawEdge( Bridge* bridge , bool iSstart );  // TODO

    void clearBridge( int bridgeNum );
    void clearBridge( Bridge* bridge );


    COORD getCoordOfCenterBridge( int bridgeNum );  // get screen position COORD{X,Y} center, of Bridge from number i
        COORD _getScreenCoordofCheesCoord(const COORD & chess ); // INNER USE ONLY convert chessCoord to screenCoord  w=w*3 h=h
        COORD _getCheesCoordOfCenterBridge(int i );           // INNER USE ONLY


    Bridge* getBridgeByInt( int bridgeNum );
};


#endif //MSPACMAN_BRIDGES_H
