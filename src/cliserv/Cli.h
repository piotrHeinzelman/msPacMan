//
// Created by Bill on 8/24/2023.
//

#ifndef MSPACMAN_CLI_H
#define MSPACMAN_CLI_H


#include <string>

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

class Cli {

protected:
#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "8080"

    int iResult;
    int iSendResult;

    char buf[DEFAULT_BUFLEN];
    int  buflen = DEFAULT_BUFLEN;

public:
    virtual    void  open( std::string serverAddr="127.0.0.1" , int port=8080 );
    virtual    char* send( char* );
    virtual    void  close();

// ? jeśli bufor prywatny to...
/*
virtual    char* getBuff();
virtual    void  setBuff( char* );
virtual    void  send();
*/

};


#endif //MSPACMAN_CLI_H