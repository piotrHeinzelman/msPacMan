//
// Created by Bill on 8/31/2023.
//

#include "TickRunner.h"
#include "Board.h"


DWORD WINAPI runTickInThread(LPVOID lpParameter ) {
    Tick t;
    while( true ) {
        t.tick();
        std::this_thread::sleep_for(std::chrono::milliseconds(100 ));
    }
}



TickRunner::TickRunner() {
    printf ("[ TICK ] :: ** start **;\n");
    // new thread!
    HANDLE myhandleA;
    myhandleA = CreateThread(0, 0, runTickInThread, 0, 0, 0);
}