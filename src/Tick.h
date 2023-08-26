//
// Created by John on 2023-08-26.
//

#ifndef MSPACMAN_TICK_H
#define MSPACMAN_TICK_H

#include <windows.h>
#include <cstdio>
#include <unistd.h>
#include <thread>

DWORD WINAPI runTickInThread(LPVOID lpParameter ) {
    while( true ) {
        printf("TICK");
        std::this_thread::sleep_for(std::chrono::milliseconds(100 ));
    }
}


class Tick {

private:


public:
    void run() {
        printf ("[ TICK ] :: run();\n");

        // new thread!
        HANDLE myhandleA;
        myhandleA = CreateThread(0, 0, runTickInThread, 0, 0, 0);

    }





};


#endif //MSPACMAN_TICK_H
