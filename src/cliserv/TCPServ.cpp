//
// Created by John on 2023-08-25.
//

#include "TCPServ.h"

void TCPServ::createForListen( int port_=8080 ) {
    std::cout<<"TCPServ::createForListen()\n";
    this->port = port_;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
        if (iResult != 0) {
            throw std::runtime_error("WSAStartup failed with error: "+iResult);
        }

    ZeroMemory( &addrInfo, sizeof( addrInfo ));
    addrInfo.ai_family = AF_INET;
    addrInfo.ai_socktype = SOCK_STREAM;
    addrInfo.ai_protocol = IPPROTO_TCP;
    addrInfo.ai_flags = AI_PASSIVE;

    // Resolve the server address and port

    iResult = getaddrinfo(NULL, , &addrInfo, &result);
    if ( iResult != 0 ) {
        WSACleanup();
        throw std::runtime_error("getaddrinfo failed with error: "+iResult );
    };

    // Create a SOCKET for the server to listen for client connections.
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        freeaddrinfo(result);
        WSACleanup();
        throw std::runtime_error("socket failed with error: "+WSAGetLastError());
    }

    // Setup the TCP listening socket
    iResult = bind( ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        throw std::runtime_error("bind failed with error: "+WSAGetLastError());
    }
    freeaddrinfo(result);

    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        closesocket(ListenSocket);
        WSACleanup();
        throw std::runtime_error("listen failed with error: "+WSAGetLastError());
    }

};

char *TCPServ::receive_() {
    std::cout<<"TCPServ::receive()\n";

    // Accept a client socket
    ClientSocket = accept(ListenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET) {
        closesocket(ListenSocket);
        WSACleanup();
        throw std::runtime_error("accept failed with error: "+ WSAGetLastError());
    }

    // ????
    // No longer need server socket
    //closesocket(ListenSocket);

    // Receive until the peer shuts down the connection
    do {
        iResult = recv(ClientSocket, buf, buflen, 0);
        if (iResult > 0) {
            printf("Bytes received: %d\n", iResult);
        }
        else if (iResult == 0)
            printf("Connection closing...\n");
        else  {
            closesocket(ClientSocket);
            WSACleanup();
            throw std::runtime_error("recv failed with error: "+WSAGetLastError());
        }
    } while (iResult > 0);
    return buf;
}




void TCPServ::send_(char *string) {
    std::cout<<"TCPServ::send(char*)\n";

    // Echo the buffer back to the sender
    // send BUF
    iSendResult = send( ClientSocket, buf, iResult, 0 );
    if (iSendResult == SOCKET_ERROR) {
        closesocket(ClientSocket);
        WSACleanup();
        throw std::runtime_error("send failed with error: "+WSAGetLastError());
    }
    printf("Bytes sent: %d\n", iSendResult);

    // shutdown the connection since we're done
    iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        closesocket(ClientSocket);
        WSACleanup();
        throw std::runtime_error("shutdown failed with error: "+WSAGetLastError());
    }

}

void TCPServ::close_() {
    std::cout<<"TCPServ::close()\n";

    // No longer need server socket
    closesocket(ListenSocket);

    // cleanup
    closesocket(ClientSocket);
    WSACleanup();
}
