//
// Created by John on 2023-08-25.
//

#ifndef MSPACMAN_UDPSERV_H
#define MSPACMAN_UDPSERV_H

#undef UNICODE

#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>


#include <iostream>

#define BUFFSIZE 256


// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")
#pragma warning(disable:4996)
//https://gist.github.com/sunmeat/02b60c8a3eaef3b8a0fb3c249d8686fd



class UDPServ {
private:
    char SERWER_IP[16] = "127.0.0.1";

    int iResult;
    WSADATA wsaData;

    int sock_fd;
    sockaddr_in server, client;
    int addrlen;

    char buf[BUFFSIZE] = {};
    char recbuf[BUFFSIZE] = {};


    void IsError(int underZero, const char* msg );

public:
    UDPServ(int port_=8080 );

    virtual ~UDPServ();

    void rec();
    void snd();
    char* getBuff();
    void setBuff( char* data );

};

#endif //MSPACMAN_UDPSERV_H
