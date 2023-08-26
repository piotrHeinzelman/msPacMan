//
// Created by Bill on 8/23/2023.
//

#ifndef MSPACMAN_ALLTEST_H
#define MSPACMAN_ALLTEST_H



#include "tests/ServTest.h"


DWORD WINAPI runTestInThread( LPVOID lpParameter ) {
    printf("CreateThread %d \n", GetCurrentThreadId());
    printf("CreateThread Server in Thread \n");

    TCPServ ts;               // domyslny port
    ts.rec(); // odbior danych przez UDP

    return 0;
}


void runMyTests() {
    printf ("[ TEST ] :: runAllTest();\n");

    HANDLE myhandleA;
    myhandleA = CreateThread(0, 0, runTestInThread, 0, 0, 0);

    printf ("[ TEST ] :: ServTest::runAllTest();\n");
    //ServTest servTest;
    //servTest.runAllTest();
    Cli c;



    }



#endif //MSPACMAN_ALLTEST_H
