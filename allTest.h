//
// Created by Bill on 8/23/2023.
//

#ifndef MSPACMAN_ALLTEST_H
#define MSPACMAN_ALLTEST_H


#include "src/UDPServ.h"
#include "src/UDPClient.h"

DWORD WINAPI runTestInThread(LPVOID lpParameter ) {
    printf("[ TEST ] :: Create Server in Thread %d\n", GetCurrentThreadId());

    UDPServ ts;               // domyslny port
    ts.rec(); // odbior danych przez UDP
    printf( "Serwer odebral:%s\n",ts.getBuff() );

    printf( "S> first reply\n" );
    ts.setBuff("first reply\n");
    ts.snd();

    bool guard=false;
    while( !guard ){
        ts.rec(); // odbior danych przez UDP
        printf( "Serwer odebral:%s\n",ts.getBuff() );

        if (ts.getBuff()[0]=='k'){ guard=true; }

        printf( "S> %s\n",ts.getBuff() );

        ts.setBuff( ts.getBuff() );
        ts.snd();
    }

    printf("Koncze!\n");
    return 0;
}


void runMyTests() {
    printf ("[ TEST ] :: runAllTest();\n");

    // new thread!
    HANDLE myhandleA;
    myhandleA = CreateThread(0, 0, runTestInThread, 0, 0, 0);



    UDPClient* c;
    c = new UDPClient();
    c->setBuff("first\0");
    printf( "C>first\n" );
    c->send();
    printf( "C odebral: %s\n", c->getBuff() );
    delete c;

    c = new UDPClient();
    printf( "C>sec\n" );
    c->setBuff("sec\0");
    c->send();
    printf( "C odebral: %s\n", c->getBuff() );


    printf( "C>koncz wasc!\n" );
    c->setBuff("koncz Wasc!\0");
    c->send();

    printf( "C odebral: %s\n", c->getBuff() );
    delete c;




    }



#endif //MSPACMAN_ALLTEST_H
