//
// Created by John on 2023-08-25.
//

#include "UDPServ.h"

void UDPServ::IsError(int underZero, const char *msg) {
 if (underZero<0){ throw std::runtime_error( msg ); }
}



UDPServ::UDPServ(int port_ ) {

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) { throw std::runtime_error("WSAStartup failed with error!"); }

    sock_fd = socket( AF_INET , SOCK_DGRAM, 0 ); // 0 is protocol
        IsError(sock_fd, "Error socket creation");


    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port_);

    iResult=bind(sock_fd, (sockaddr*)&server, sizeof(server));
        IsError(iResult, "Bind failed");

    // binds done

    iResult = bind( sock_fd , (const sockaddr*) &server , sizeof (server) );
        IsError(sock_fd, "Error socket creation");

    printf("UDPServ::UDPServ()\n      port:%i, sock_fd:%i, servAddr: %x\n" , port_ , sock_fd, server.sin_addr.S_un.S_addr );

}


void UDPServ::rec(){
        // try to receive some data, this is a blocking call
        int message_len;
        int slen = sizeof(sockaddr_in);
        ZeroMemory(recbuf,BUFFSIZE);
        message_len = recvfrom(sock_fd, recbuf, BUFFSIZE, 0, (sockaddr*)&client, &slen) ;
        if (message_len== SOCKET_ERROR){
                printf("recvfrom() failed with error code: %d", WSAGetLastError());
        }
        //printf("Received packet from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
}



void UDPServ::snd() {
    iResult = sendto(sock_fd, buf, strlen(buf), 0, (sockaddr *) &client, sizeof(sockaddr_in));
    if (iResult == SOCKET_ERROR) {
        printf("sendto() failed with error code: %d", WSAGetLastError());
    }
}


char* UDPServ::getBuff(){
    return recbuf;
};


void UDPServ::setBuff(char* data ){
    for(int i=0;i<BUFFSIZE;i++){
        buf[i] = data[i];
    };
}


UDPServ::~UDPServ() {
    closesocket(sock_fd);
    WSACleanup();
}
