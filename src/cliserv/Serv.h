//
// Created by Bill on 8/24/2023.
//

#ifndef MSPACMAN_SERV_H
#define MSPACMAN_SERV_H

/***

 Interfejs dla komunikacji strona Serwer.
 implementowana przez Socket
 ale także przez inne rozwiązania - na potrzeby testów

 "Nie chcę aby użytkownicy wiedzieli że udostępniam im interfejs..." - czysty kod
 dlatego klasa ma naswę Serv a nie IServ

 przyzwyczajenia z Java gdzie klasa ma nazwę pisamą z wielkiej litery a nazwa obiektu z małej.
 w C uzywa się raczej małych liter std::string s a nazwa zmiennej jest zwykle krótrza niż klasa.

 w razie błędów połaczenia implementacja będzie wyrzucała błąd

 */
#include <cstdio>

#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

class Serv {

protected:


public:





// ? jeśli bufor prywatny to...
/*
virtual    char* getBuff();
virtual    void  setBuff( char* );
virtual    void  receive();
virtual    void  send();
*/

};


#endif //MSPACMAN_SERV_H
