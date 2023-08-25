//
// Created by John on 2023-08-25.
//

#ifndef MSPACMAN_TCPSERV_H
#define MSPACMAN_TCPSERV_H

#include "Serv.h"

class TCPServ : public Serv {

private:

public:
     void createForListen();
     char *receive();
     void send(char *string);
     void close();

public:

};

#endif //MSPACMAN_TCPSERV_H
