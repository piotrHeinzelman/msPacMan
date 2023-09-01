//
// Created by Bill on 8/24/2023.
//

#include "UDPClient.h"

UDPClient::UDPClient() {

    // initialise winsock
    WSADATA ws;
    //    printf("Initialising Winsock...");
    if (WSAStartup(MAKEWORD(2, 2), &ws) != 0) {
        throw std::runtime_error ("Failed. Error Code: "+WSAGetLastError() );
    }
    //printf("Initialised.\n");

    // create socket
    if ((client_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR) {
            throw std::runtime_error("socket() failed with error code: "+WSAGetLastError() );
    }

    // setup address structure
    memset((char *) &server, 0, sizeof(server));
        server.sin_family = AF_INET;
        server.sin_port = htons(PORT);
        server.sin_addr.S_un.S_addr = inet_addr(SERVER);
    }


void UDPClient::send() {

    // send the message
    if (sendto(client_socket, buf, strlen(buf), 0, (sockaddr *) &server, sizeof(sockaddr_in)) == SOCKET_ERROR) {
            printf("sendto() failed with error code: %d", WSAGetLastError());
    }

    // try to receive some data, this is a blocking call
    int slen = sizeof(sockaddr_in);
    int answer_length;
    ZeroMemory(recbuf,BUFFSIZE);
    answer_length = recvfrom(client_socket, recbuf, BUFFSIZE, 0, (sockaddr *) &server, &slen);
    if (answer_length == SOCKET_ERROR) {
            printf("recvfrom() failed with error code: %d", WSAGetLastError());
    }
    //printf( "\nLEN:%i" , answer_length);
}



char* UDPClient::getBuff(){
    return recbuf;
};

void UDPClient::setBuff(char* data ){
    for(int i=0;i<BUFFSIZE;i++){
        buf[i] = data[i];
    };
}

UDPClient::~UDPClient() {
    closesocket(client_socket);
    WSACleanup();
};
