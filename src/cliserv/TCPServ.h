//
// Created by John on 2023-08-25.
//

#ifndef MSPACMAN_TCPSERV_H
#define MSPACMAN_TCPSERV_H

#undef UNICODE

#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include "Serv.h"

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")



class TCPServ : public Serv {

private:
    WSADATA wsaData;
    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;


    struct addrinfo *result = NULL;
    struct addrinfo addrInfo;



public:
     void createForListen( int port_ );
     char *receive_();
     void send_(char *string);
     void close_();


};

#endif //MSPACMAN_TCPSERV_H
