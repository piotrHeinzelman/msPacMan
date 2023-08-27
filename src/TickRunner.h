//
// Created by John on 2023-08-26.
//

#ifndef MSPACMAN_TICKRUNNER_H
#define MSPACMAN_TICKRUNNER_H

#include <windows.h>
#include <cstdio>
#include <unistd.h>
#include <thread>
#include "Tick.h"

DWORD WINAPI runTickInThread(LPVOID lpParameter ) {
    Tick t;
    while( true ) {
        t.tick();
        std::this_thread::sleep_for(std::chrono::milliseconds(100 ));
    }
}


void TickRun() {
    printf ("[ TICK ] :: ** start **;\n");
    // new thread!
    HANDLE myhandleA;
    myhandleA = CreateThread(0, 0, runTickInThread, 0, 0, 0);

}


#endif //MSPACMAN_TICKRUNNER_H
