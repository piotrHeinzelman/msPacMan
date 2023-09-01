
#include <iostream>
#include "allTest.h"
#include "src/ConsoleDraw.h"
#include "tests/CppTests.h"
#include "tests/lastTest.h"


int main() {

    bool cppTest=!true;  // uruchomic cppcheck
    bool allTest=!true;  // czy uruchamic wszystkie testy
    bool last_Test=true;  // czy uruchamia ostatni test (nad ktorym wlasnie pracuje) ?
    bool exitAfterTests=true; // czy po zakonczeniu testow zakonczyc aplikacje ?


    if ( cppTest ) { CppTests cppt; cppt.BridgesTest();  }
    if ( allTest ) runAllTests();
    //if ( lastTest ) runLastTests();
    if ( last_Test ) run_Last_Test();



    if (exitAfterTests){ return 0; }
    //std::cout << "Hello, World!" << std::endl;
    Board board;
    //sleep(50);
    //createServer();


    return 0;
}
