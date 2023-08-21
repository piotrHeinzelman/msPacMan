//
// Created by John on 8/20/2023.
//

#ifndef XXX_COMM_H
#define XXX_COMM_H

#include <iostream>
#include <string>
#include <winsock2.h>
#include <windows.h>


class comm {

private:
    const char* serverAddr;
    static const size_t buff_SIZE = 512;

    WSADATA wsaData;
    struct sockaddr_in srv_addr;
    char rec_buf[buff_SIZE];
    char send_buf[buff_SIZE];

    u_short serverPort;
    int sock_fd; // deskryptor gniazda


public:
    int connect(  std::string serverAddr , int serverPort );
    int se_nd( char* buf );
    int se_nd(const char *);
    void disconnect();

};


#endif //XXX_COMM_H
