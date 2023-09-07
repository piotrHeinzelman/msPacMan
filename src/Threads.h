//
// Created by Bill on 9/6/2023.
//

#ifndef MSPACMAN_THREADS_H
#define MSPACMAN_THREADS_H

#include <thread>
#include "UDPClient.h"
#include "UDPServ.h"


/*
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
*/





#endif //MSPACMAN_THREADS_H
