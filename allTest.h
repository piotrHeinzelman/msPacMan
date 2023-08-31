//
// Created by Bill on 8/23/2023.
//

#ifndef MSPACMAN_ALLTEST_H
#define MSPACMAN_ALLTEST_H


#include "src/UDPServ.h"
#include "src/UDPClient.h"
#include "src/TickRunner.h"
#include "tests/BoardTest.h"
#include "src/Bridges.h"


DWORD WINAPI runTestInThread(LPVOID lpParameter ) {
    printf("[ TEST ] :: Create Server in Thread %d\n", GetCurrentThreadId());

    UDPServ ts;               // domyslny port
    ts.rec(); // odbior danych przez UDP
    printf( "S<%s\n",ts.getBuff() );

    printf( "S>first reply\n" );
    ts.setBuff("first reply");
    ts.snd();

    bool guard=false;
    while( !guard ){
        ts.rec(); // odbior danych przez UDP
        printf( "S<%s\n",ts.getBuff() );


        if (ts.getBuff()[0]=='k'){ guard=true; }
        for (int i=0;i<3;i++){ ts.getBuff()[i]=(ts.getBuff()[i])+1; }
        printf( "S>%s\n",ts.getBuff() );

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
    c->setBuff("first");
    printf( "C>first\n" );
    c->send();
    printf( "C<%s\n", c->getBuff() );
    delete c;

    c = new UDPClient();
    printf( "C>sec\n" );
    c->setBuff("sec");
    c->send();
    printf( "C<%s\n", c->getBuff() );


    printf( "C>koncz wasc!\n" );
    c->setBuff("koncz Wasc!");
    c->send();

    printf( "C<%s\n", c->getBuff() );
    delete c;




    }

void runAllTests(){
    // ** TEST ** Client/Server communication
    runMyTests();  // uruchamia w innym watki serwer ktory nasuchuje w petli
    // i odpowiada tym samym,
    // jesli otrzyma w parametrze "k" to konczy dzialanie

    // ** TEST ** tick
    TickRun();  // uruchamia runTickInThread()  w innym watku
    //           runTickInThread() uruchamia w petli Tick::tick(); co 500 ms
    sleep(5);       // usypia glowny watek na 5 sek, dzieki temu widac czy dzialaja inne watki


    // Board
    // podgląd planszy




}


void runLastTests() {
    Bridges br;
    br.drawBoard();
}
#endif //MSPACMAN_ALLTEST_H
