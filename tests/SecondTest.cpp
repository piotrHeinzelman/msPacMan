//
// Created by John on 9/4/2023.
//

#include <iostream>
#include "SecondTest.h"
#include "../src/Bridge.h"
#include "../src/Bridges.h"

void SecondTest::runTest() {
    std::cout << "second test runTest();\n";

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




}
