//
// Created by John on 2023-08-25.
//

#include "TCPServ.h"


TCPServ::TCPServ( int port_ ) {
    port = htons( port_ );
    printf("TCPServ::TCPServ(), port:%i\n" , port_ );
}
