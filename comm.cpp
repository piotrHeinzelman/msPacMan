//
// Created by John on 8/20/2023.
//

#include "comm.h"
#include <winsock2.h>
#include <windows.h>


int comm::connect( std::string  _serverAddr , int _serverPort ){
    serverAddr = _serverAddr.c_str();
    serverPort = ( u_short )_serverPort ;

    int sock_fd; // deskryptor gniazda
/*
    struct sockaddr_in srv_addr; // mój adres
    // utworzenie gniazda TCP
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == SOCKET_ERROR)
         {
         std::cout << "Blad tworzenia gniazda\n";
         WSACleanup();
         exit(1);
         }
/*
     // ustawienie adresu
     srv_addr.sin_family = AF_INET; // INET - czyli na dziś jedyna słuszna opcja
     srv_addr.sin_port = serverPort; // port musi być konwertowany
     srv_addr.sin_addr.s_addr = inet_addr( serverAddr );
     memset(&(srv_addr.sin_zero), '\0', 8); // zerowanie reszty
*/


    return 1;
}

void comm::disconnect() {
    std::cout << "disconnect from: " << serverAddr << ":" << serverPort;
}