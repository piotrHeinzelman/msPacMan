//
// Created by Bill on 8/24/2023.
//

#ifndef MSPACMAN_UDPCLIENT_H
#define MSPACMAN_UDPCLIENT_H


#include <string>
#include <iostream>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")
#pragma warning(disable:4996)

#define BUFFSIZE 256

/***

 Interfejs dla komunikacji strona Client.
 implementowana przez Socket
 ale także przez inne rozwiązania - na potrzeby testów

 "Nie chcę aby użytkownicy wiedzieli że udostępniam im interfejs..." - czysty kod
 dlatego klasa ma naswę Serv a nie IServ

 przyzwyczajenia z Java gdzie klasa ma nazwę pisamą z wielkiej litery a nazwa obiektu z małej.
 w C uzywa się raczej małych liter std::string s a nazwa zmiennej jest zwykle krótrza niż klasa.

 w razie błędów połaczenia implementacja będzie wyrzucała błąd

 */

class UDPClient {

private:
    char SERVER[16] = "127.0.0.1";  // or "localhost" - ip address of UDP server
    int PORT = 8080;  // the port on which to listen for incoming data
    sockaddr_in server;
    int client_socket;

    char buf[BUFFSIZE]={0};
    char redbuf[BUFFSIZE]={0};

public:
    UDPClient();
    virtual ~UDPClient();

    void send();
    char* getBuff();
    void setBuff( char* data );

};


#endif //MSPACMAN_UDPCLIENT_H
