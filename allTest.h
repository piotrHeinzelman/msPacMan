//
// Created by Bill on 8/23/2023.
//

#ifndef MSPACMAN_ALLTEST_H
#define MSPACMAN_ALLTEST_H


#include "src/UDPServ.h"
#include "src/UDPClient.h"
#include "src/TickRunner.h"
#include "src/Bridges.h"
#include "src/Board.h"


DWORD WINAPI runTestInThread_test(LPVOID lpParameter ) {
    printf("[ TEST ] :: Create Server in Thread %d\n", GetCurrentThreadId());

    UDPServ ts;               // domyslny port
    ts.rec(); // odbior danych przez UDP
    printf( "S<%s\n",ts.getBuff() );

    printf( "S>first reply\n" );
    ts.setBuff((char*)"first reply");
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
    myhandleA = CreateThread(0, 0, runTestInThread_test, 0, 0, 0);



    UDPClient* c;
    c = new UDPClient();
    c->setBuff((char*)"first");
    printf( "C>first\n" );
    c->send();
    printf( "C<%s\n", c->getBuff() );
    delete c;

    c = new UDPClient();
    printf( "C>sec\n" );
    c->setBuff((char*)"sec");
    c->send();
    printf( "C<%s\n", c->getBuff() );


    printf( "C>koncz wasc!\n" );
    c->setBuff((char*)"koncz Wasc!");
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
    //TickRunner tickRunner;
    //tickRunner.TickRun();  // uruchamia runTickInThread()  w innym watku
    //           runTickInThread() uruchamia w petli Tick::tick(); co 500 ms
    sleep(5);       // usypia glowny watek na 5 sek, dzieki temu widac czy dzialaja inne watki


    // Board
    // podgląd planszy




}


void runLastTests() {

    // test coordinate
    /*
    std::cout <<"\n";
    Board b;
    Bridges br;
    //b.drawBoard();

    Mob* Pac = new Mob( 4, "mr. Pac" , &b, false );
    b.addMob( Pac );
    b.insertMobAtBridge( Pac, 10 , 3 , false );
    //std::cout << "exists: N:" <<Pac->getExits().count(DIRECT::N)  <<"\n";
    //std::cout << "exists: E:" <<Pac->getExits().count(DIRECT::E)  <<"\n";


    Mob* WhileLady = new Mob ( 1 , "White Lady" , &b , true );
    b.addMob( WhileLady );
    b.insertMobAtBridge( WhileLady, 10 , 4 , false );
    //std::cout << "exists: N:" <<WhileLady->getExits().count(DIRECT::N)  <<"\n";
    //std::cout << "exists: E:" <<WhileLady->getExits().count(DIRECT::E)  <<"\n";


    ConsoleDraw draw;
                draw.WriteColourChar({0,0}, '0');
                std::cout <<"\n\n\n"<< "Bridge: "<< Pac->getBridge() << ", bridgeCenter coords: X: " << br.getCoordOfCenterBridge ( Pac->getBridge()).X << ",Y: " << br.getCoordOfCenterBridge ( Pac->getBridge()).Y;
                int startEdge = br.edgeChessPosition( Pac->getBridge() , true ); int endEdge = br.edgeChessPosition( Pac->getBridge() , false );
                std::cout <<"\n"<< "startEdge coords: X: " << br.getCoordOfEdge( startEdge).X << ",Y: " << br.getCoordOfEdge ( startEdge).Y << ", endEdge coords: X: " << br.getCoordOfEdge( endEdge ).X << ",Y: " << br.getCoordOfEdge ( endEdge ).Y;

    draw.WriteColourChar(br.getCoordOfEdge ( startEdge), 's');
    draw.WriteColourChar(br.getCoordOfCenterBridge ( Pac->getBridge()), 'c');
    draw.WriteColourChar(br.getCoordOfEdge ( endEdge), 'e');


    std::cout << "\n\n\n\n\n";
    b.drawOneMob( Pac );
    b.drawOneMob( WhileLady );
    */

    std::cout << "\n\n\n\n\n\n\n\n\n\n";
    ConsoleDraw draw;
    draw.WriteColourChar({0,0}, '0');
    Board b;
    Bridges br;
     //\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    Mob* Pac = new Mob( 4, "mr. Pac" , &b, false );
    b.addMob( Pac );
    b.insertMobAtBridge( Pac, 1 , STEPS , true );

    Mob* WhileLady = new Mob ( 1 , "White Lady" , &b , true );
    b.addMob( WhileLady );
    b.insertMobAtBridge( WhileLady, 3 , STEPS , true );



    b.drawOneMob( Pac );     b.drawOneMob( WhileLady );
    b.moveMobNextStep( Pac ); b.moveMobNextStep( WhileLady );
    b.drawAllMob();
    b.moveAllMobs();

    Pac->setDirection( DIRECT::W );
    WhileLady->setDirection( DIRECT::E );

    char chr;
    DWORD written;
    for (int i=0;i<150;i++) {
        draw.WriteColourChar({0, 0}, (char)i);
        sleep(1);
    }

    return;

    for (int i=0;i<150;i++){
        //b.clearAllUsedBridge();
        b.moveAllMobs();
        b.drawAllMob();
        //std::cout << i;
        //sleep(1);

        usleep(1000);
    }

    sleep(10);
return;

    Pac->setDirection( DIRECT::N );

    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();
    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();
    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();
    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();
    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();
    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();
    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();
    Pac->setNextDirection( DIRECT::E );
    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();
    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();
    Pac->setNextDirection( DIRECT::S );

    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();
    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();
    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();

    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();
    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();
    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();
    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();
    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();
    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();
    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();
    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();
    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();
    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();
    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();
    b.moveMobNextStep( Pac ); b.drawOneMob( Pac );std::cout << Pac->getStep();
    sleep(15);

}
#endif //MSPACMAN_ALLTEST_H
