
#include <iostream>
#include <future>
#include <thread>
#include "tests/allTest.h"
#include "src/ConsoleDraw.h"
#include "tests/CppTests.h"
#include "src/UDPServ.h"
#include "tests/SecondTest.h"







int main() {


    // create server // TURN OFF< read key
    //HANDLE thread = CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(createClient), NULL, 0, NULL);


    bool cppTest=!true;  // uruchomic cppcheck
    bool secTest=true;  // uruchomic secondtest
    bool allTest=!true;  // czy uruchamic wszystkie testy
    bool lastTest=!true;  // czy uruchamia ostatni test (nad ktorym wlasnie pracuje) ?
    bool exitAfterTests=true; // czy po zakonczeniu testow zakonczyc aplikacje ?


    if ( cppTest ) { CppTests cppt; cppt.BridgesTest();  }
    if ( allTest ) runAllTests();
    if ( lastTest ) runLastTests();
    if ( secTest ) {
        SecondTest sc;
                   sc.runTest();
    }

    if (exitAfterTests){ return 0; }


    //std::cout << "Hello, World!" << std::endl;


    Board b1;
    b1.prepare();
    b1.drawBoard();
    b1.drawAllDots();


    while(true){
        std::this_thread::sleep_for(std::chrono::milliseconds(100 ));
        b1.clearAllUsedBridge();
        b1.moveAllMobs();
        b1.drawAllMob();
        b1.allMobCheckcontroller();
        //std::cout << "b";
    }


    //return 0;
}
