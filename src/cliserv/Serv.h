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

class Serv {

protected:


public:

    // konstrktor z domyslnym numerem portu
    Serv( int port_=8080 ); // konstruktor z domyslnym portem




// ? jeśli bufor prywatny to...
/*
virtual    char* getBuff();
virtual    void  setBuff( char* );
virtual    void  receive();
virtual    void  send();
*/

};


#endif //MSPACMAN_SERV_H
