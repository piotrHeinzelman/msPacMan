//
// Created by John on 9/4/2023.
//

#include <iostream>
#include "SecondTest.h"
#include "../src/Bridge.h"
#include "../src/Bridges.h"

void SecondTest::runTest() {
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nsecond test runTest();\n";

    Bridge* wB = new Bridge(1);
    std::cout << "startEdge:" << wB->getStartEdge() << ", endEdge:  " << wB->getEndEdge() << "\n";

    Bridge* hB = new Bridge(10);
    std::cout << "startEdge:" << hB->getStartEdge() << ", endEdge:  " << hB->getEndEdge() << "\n";

    Bridges mapa;
             wB = mapa.getBridgeByInt(1);
                    std::cout << "startEdge:" << wB->getStartEdge() << ", endEdge:  " << wB->getEndEdge() << "\n";
                    std::cout << "startWay N:" << wB->getStartWays().n  << ", W:" << wB->getStartWays().w << ", S:" << wB->getStartWays().s << ", E:" << wB->getStartWays().e << "\n";

    hB = mapa.getBridgeByInt(10);
                    std::cout << "startEdge:" << hB->getStartEdge() << ", endEdge:  " << hB->getEndEdge() << "\n";


    ConsoleDraw draw;
                draw.WriteColourChar( -1,-1,'@' ,0xA0 );
 /*
  * mapa.DrawCenterPiontOfWall(3);
    mapa.DrawCenterPiontOfWall(14);
    mapa.DrawCenterPiontOfWall(5);

    mapa.drawBridge(3);
    mapa.drawBridge(14);
    mapa.drawBridge(76);
    mapa.drawBridge(5);
*/




    mapa.DrawCenterPiontOfWall(22);
    mapa.DrawCenterPiontOfWall(24);
    mapa.drawEdge(23,true);

//    mapa.drawBridge(10);
//    mapa.drawBridge(30);
//    mapa.drawBridge(21);
    //mapa.drawBridge(3);
    //mapa.drawBridge(3);
    //mapa.drawBridge(1);
    //mapa.drawBridge(1);
/*
    mapa.drawEdge(1);
    mapa.drawEdge(3);
    mapa.drawEdge(5);
    mapa.drawEdge(7);
*/

}
