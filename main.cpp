#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <process.h>
//#include "info/con_serv.h"

#include "allTest.h"
#include "src/test.h"




DWORD WINAPI mythreadA( LPVOID lpParameter )
{
    printf("CreateThread %d \n", GetCurrentThreadId());
    return 0;
}

unsigned int __stdcall mythreadB(void* data)
{
    printf("_beginthreadex %d \n", GetCurrentThreadId());
    return 0;
}

void mythreadC(void* data)
{
    printf("_beginthread %d \n", GetCurrentThreadId());
}


int main() {

    HANDLE myhandleA, myhandleB, myhandleC;

    myhandleA = CreateThread(0, 0, mythreadA, 0, 0, 0);

    myhandleB = (HANDLE)_beginthreadex(0, 0, &mythreadB, 0, 0, 0);
    WaitForSingleObject(myhandleB, INFINITE);


    myhandleC = (HANDLE)_beginthread(&mythreadC, 0, 0);
    getchar();

    return 0;


    // run test
    if ( true ) {
        runMyTests();
        return 0; }


    std::cout << "Hello, World!" << std::endl;
    //createServer();


    return 0;
}
