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
    u_short serverPort;
    int sock_fd; // deskryptor gniazda

public:
    int connect(  std::string serverAddr , int serverPort );
    void disconnect();

};


#endif //XXX_COMM_H
