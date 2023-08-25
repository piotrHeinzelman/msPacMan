//
// Created by John on 2023-08-25.
//

#include <iostream>
#include "TCPServ.h"
/*
void  TCPServ::createForListen(){

}
*/
void TCPServ::createForListen() {
    std::cout<<"TCPServ::createForListen()\n";
}

char *TCPServ::receive() {
    std::cout<<"TCPServ::receive()\n";
    return buf;
}

void TCPServ::send(char *string) {
    std::cout<<"TCPServ::send(char*)\n";
}

void TCPServ::close() {
    std::cout<<"TCPServ::close()\n";
}
