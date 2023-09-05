//
// Created by John on 9/4/2023.
//

#include <iostream>
#include <unistd.h>
#include "SecondTest.h"
#include "../src/Bridge.h"
#include "../src/Bridges.h"
#include "../src/Board.h"

void SecondTest::runTest() {

  //  std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nsecond test runTest();\n";
/*
    Bridge* wB = new Bridge(1);
    std::cout << "startEdge:" << wB->getStartEdge() << ", endEdge:  " << wB->getEndEdge() << "\n";

    Bridge* hB = new Bridge(10);
    std::cout << "startEdge:" << hB->getStartEdge() << ", endEdge:  " << hB->getEndEdge() << "\n";

    Bridges mapa;
    mapa.drawAllBridges();
             wB = mapa.getBridgeByInt(1);
                    std::cout << "startEdge:" << wB->getStartEdge() << ", endEdge:  " << wB->getEndEdge() << "\n";
                    std::cout << "startWay N:" << wB->getStartWays().n  << ", W:" << wB->getStartWays().w << ", S:" << wB->getStartWays().s << ", E:" << wB->getStartWays().e << "\n";

    hB = mapa.getBridgeByInt(10);
                    std::cout << "startEdge:" << hB->getStartEdge() << ", endEdge:  " << hB->getEndEdge() << "\n";
                    std::cout << "centerPoint x:" << wB->getCenterPoint().X << ", y:" <<wB->getCenterPoint().Y << "\n";


    ConsoleDraw draw;
                draw.WriteColourChar( -1,-1,'@' ,0xA0 );
                hB->getCenterPoint();


    Bridge* b1_w = mapa.getBridgeByInt(1);
     Bridge* b3_w = mapa.getBridgeByInt(3);
     Bridge* b5_w = mapa.getBridgeByInt(5);
     Bridge* b14_h = mapa.getBridgeByInt(14);

    mapa.DrawCenterPiontOfWall(b3_w);
    mapa.DrawCenterPiontOfWall(b5_w);
    mapa.DrawCenterPiontOfWall(b14_h);



    mapa.drawEdge(b1_w, true);
    mapa.drawEdge(b1_w, false);

    mapa.drawEdge(b3_w, true);
    mapa.drawEdge(b3_w, false);


        mapa.drawAllBridges();
        */

Board b;
      b.drawBoard();
      b.drawAllMob();

  //  Bridges mapa;
  //  mapa.drawAllBridges();

  sleep(5);

}
