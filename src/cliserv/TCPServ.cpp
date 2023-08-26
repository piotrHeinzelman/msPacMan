//
// Created by John on 2023-08-25.
//

#include "TCPServ.h"

void TCPServ::IsError(int underZero, const char *msg) {
 if (underZero<0){ throw std::runtime_error( msg ); }
}



TCPServ::TCPServ( int port_ ) {

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

    printf("TCPServ::TCPServ()\n      port:%i, sock_fd:%i, servAddr: %x\n" , port_ , sock_fd, server.sin_addr.S_un.S_addr );



    //closesocket(sock_fd);
    //WSACleanup();
}


int TCPServ::rec(){
    while (true)
    {
        printf("Waiting for data...");
        fflush(stdout);


        // try to receive some data, this is a blocking call
        int message_len;
        int slen = sizeof(sockaddr_in);
        if (message_len = recvfrom(sock_fd, buf, BUFFSIZE, 0, (sockaddr*)&client, &slen) == SOCKET_ERROR)
        {
            printf("recvfrom() failed with error code: %d", WSAGetLastError());
            exit(0);
        }

        // print details of the client/peer and the data received
        printf("Received packet from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        printf("Data: %s\n", buf);

        std::cin.getline(buf, BUFFSIZE);

        // reply the client with 2the same data
        if (sendto(sock_fd, buf, strlen(buf), 0, (sockaddr*)&client, sizeof(sockaddr_in)) == SOCKET_ERROR)
        {
            printf("sendto() failed with error code: %d", WSAGetLastError());
            // return 3;
        }
    }










    int i = recvfrom(sock_fd, buf, BUFFSIZE, 0, (sockaddr *) &server, &addrlen);
    if (i>0) {
        printf("%i\n",i);
    }


}