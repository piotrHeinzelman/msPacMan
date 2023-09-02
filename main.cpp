
#include <iostream>
#include "allTest.h"
#include "src/ConsoleDraw.h"
#include "tests/CppTests.h"
#include "src/UDPServ.h"







int main() {

    //createClient(); return 0;

    Board b1;
    b1.prepare();
    //b1.CreateServer( b1.getPlayersMob() );
    //b1.RunBoardTick();
    b1.RunBoardTick();

    while (true){
        b1.BoardTick();
    }





    sleep(20);
    return 0;


    bool cppTest=!true;  // uruchomic cppcheck
    bool allTest=!true;  // czy uruchamic wszystkie testy
    bool lastTest=true;  // czy uruchamia ostatni test (nad ktorym wlasnie pracuje) ?
    bool exitAfterTests=true; // czy po zakonczeniu testow zakonczyc aplikacje ?


    if ( cppTest ) { CppTests cppt; cppt.BridgesTest();  }
    if ( allTest ) runAllTests();
    if ( lastTest ) runLastTests();

    if (exitAfterTests){ return 0; }
    //std::cout << "Hello, World!" << std::endl;
    Board board;
    sleep(50);
    //createServer();


    //return 0;
}
