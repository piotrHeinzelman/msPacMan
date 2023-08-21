//
// Created by John on 8/20/2023.
//

#include "comm.h"
#include <winsock2.h>
#include <windows.h>


int comm::connect( std::string  _serverAddr , int _serverPort ){

    serverAddr = _serverAddr.c_str();
    serverPort = htons(_serverPort ) ;



    try{
        int iResult;
        // To specyficzne dla windows
        iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (iResult != 0) {
            throw ( "WSAStartup nie udało sie, iResult = " + iResult );
        }

        // utworzenie gniazda TCP
        if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == SOCKET_ERROR) {
            std::cout << "Blad tworzenia gniazda\n";
            WSACleanup();
            throw ( "Blad tworzenia gniazda" );
        }

        struct sockaddr_in srv_addr;
        // ustawienie adresu
        srv_addr.sin_family = AF_INET; // INET - czyli na dziś jedyna słuszna opcja
        srv_addr.sin_port = serverPort; // port musi być konwertowany
        srv_addr.sin_addr.s_addr = inet_addr( serverAddr );
        memset(&(srv_addr.sin_zero), '\0', 8); // zerowanie reszty

        return sock_fd;
    }
    catch( std::exception e ){
        std::cerr << e.what();
        std::cout << e.what();
        return -1;
    }
    return 1;
}


int comm::se_nd(const char *str  ){
    sprintf ( send_buf , str );
    return se_nd( send_buf );
}

int comm::se_nd( char* buf1  ){
        // tu już mamy połączenie - można wysłać hello
        //char buf[g_BSIZE];
        //std::cout <<  strlen(buf);
        //std::cout <<  buf;
        //if (true) return -1;

        char buf[512];
        sprintf(buf, "/a=1");

        if (  send ( sock_fd, buf, strlen(buf), 0)==SOCKET_ERROR ) {
            WSACleanup();
            std::cout << "Blad wysylania\n";
            std::cerr << "Blad wysylania\n";
            throw  std::runtime_error ("Blad wysylania\n" );
        }

    if (true) return -1;
    int nbytes = recv(sock_fd, rec_buf, buff_SIZE, 0);
    if (nbytes==SOCKET_ERROR) {
        WSACleanup();
        throw  ("Blad odbierania odpowiedzi");
        }
     buf[nbytes] = '\0';
     // wyœwietlamy co odebraliœmy
     std::cout << "rec:" << rec_buf << "\r\n";


    return 1;
}

void comm::disconnect() {
    std::cout << "disconnect from: " << serverAddr << ":" << serverPort;
}