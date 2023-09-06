
#include <iostream>
#include <future>
#include <thread>
#include "tests/allTest.h"
#include "src/ConsoleDraw.h"
#include "tests/CppTests.h"
#include "src/UDPServ.h"
#include "tests/SecondTest.h"
#include "src/Threads.h"



int main() {

    // create server // TURN OFF< read key
    //HANDLE thread = CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(createClient), &b1, 1, NULL);


    bool cppTest=!true;  // uruchomic cppcheck
    bool secTest=!true;  // uruchomic secondtest
    bool allTest=!true;  // czy uruchamic wszystkie testy
    bool lastTest=!true;  // czy uruchamia ostatni test (nad ktorym wlasnie pracuje) ?
    bool exitAfterTests=!true; // czy po zakonczeniu testow zakonczyc aplikacje ?


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
    b1.drawAllMob();

    b1.getPlayersMob()->setNextDirection( DIRECT::E );
    b1.getPlayersMob()->setDirection( DIRECT::E );






    HANDLE thread = CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>( RefreshBoard ), &b1, 1, NULL);


    Mob* player = b1.getPlayersMob();
    DIRECT activeDirection=DIRECT::STOP;
    DIRECT d;
    while(true){
        if (GetKeyState(VK_UP   ) < 0 ) { d=DIRECT::N; if (d != activeDirection ) { activeDirection=d; player->setNextDirection( d ); }}
        if (GetKeyState(VK_DOWN ) < 0 ) { d=DIRECT::S; if (d != activeDirection ) { activeDirection=d; player->setNextDirection( d ); }}
        if (GetKeyState(VK_LEFT ) < 0 ) { d=DIRECT::W; if (d != activeDirection ) { activeDirection=d; player->setNextDirection( d ); }}
        if (GetKeyState(VK_RIGHT) < 0 ) { d=DIRECT::E; if (d != activeDirection ) { activeDirection=d; player->setNextDirection( d ); }}
        if (GetKeyState(VK_SPACE) < 0 ) { std::cout << "Bridge:" << player->getBridge()->getBridgeNum()<<", position:"<<player->getStep()<<"\n"; }
    }


    //return 0;
}
