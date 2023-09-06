//
// Created by Bill on 9/6/2023.
//

#ifndef MSPACMAN_THREADS_H
#define MSPACMAN_THREADS_H

#include <thread>
#include "UDPClient.h"
#include "UDPServ.h"
#include "Board.h"


void createClient_(){
    UDPClient* c;
    c = new UDPClient();
    char buff[3]={0};
    char reply[3]={0};
    bool echo=false;

    while( true ){
        while( true ){
            if (GetKeyState(VK_UP   ) < 0 && (buff[0]!='N')) { buff[0]='N' ; if (echo) {std::cout << buff[0]; } ; c->setBuff(buff); c->send(); c->getBuff(); }
            if (GetKeyState(VK_DOWN ) < 0 && (buff[0]!='S')) { buff[0]='S' ; if (echo) {std::cout << buff[0]; } ; c->setBuff(buff); c->send(); c->getBuff(); }
            if (GetKeyState(VK_LEFT ) < 0 && (buff[0]!='W')) { buff[0]='W' ; if (echo) {std::cout << buff[0]; } ; c->setBuff(buff); c->send(); c->getBuff(); }
            if (GetKeyState(VK_RIGHT) < 0 && (buff[0]!='E')) { buff[0]='E' ; if (echo) {std::cout << buff[0]; } ; c->setBuff(buff); c->send(); c->getBuff(); }
        }
    }
}

void RefreshBoard( Board* board ) {
    int i=0;
    while(true){
        board->showInfo( board->getPlayersMob() );
        board->clearAllUsedBridge();
        board->moveAllMobs();
        board->drawAllMob();
        board->drawDotsOfUsedBridge();

        i++;
        if (i%20==0)  board->allMobCheckcontroller();

        std::this_thread::sleep_for(std::chrono::milliseconds(1000/20));
/*
        b.getPlayersMob()->setDirection( DIRECT::E);
        b.getPlayersMob()->setNextDirection( DIRECT::S);
        b.drawAllMob();


        for ( int i=0;i<30;i++ ){
            if (i==5) b.getPlayersMob()->setNextDirection( DIRECT::S);
            b.moveAllMobs();
            b.drawAllMob();
        }





    std::cout << "1";
    board->clearAllUsedBridge();
    board->moveAllMobs();
    board->drawAllMob();
    */

    }
}





#endif //MSPACMAN_THREADS_H
