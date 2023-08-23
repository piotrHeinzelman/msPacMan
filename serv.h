//
// Created by John on 8/21/2023.
//

/*
* File: CDemoSrvSocket.h
* Author: Paweł Wnuk
*
*/

 /** Implementacja przykładowego serwera - nie jest specjalnie skomplikowana,
 * ponieważ większość logiki jest zaimplementowana w klasach parsera oraz
 * mapy użytkowników.
 *
 * Ta klasa odpowiada w zasadzie jedynie za pobranie linii i przygotowania
 * odpowiedzi.
 */


#ifndef XXX_SERV_H
#define XXX_SERV_H

//https://www.jetbrains.com/help/clion/quick-cmake-tutorial.html#link-libs
//https://learn.microsoft.com/en-us/windows/win32/winsock/complete-client-code

#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#pragma comment (lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

class serv : public tcp_keepalive {

};


#endif //XXX_SERV_H
