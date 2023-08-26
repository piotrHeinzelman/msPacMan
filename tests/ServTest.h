//
// Created by Bill on 8/24/2023.
//

#ifndef MSPACMAN_SERVTEST_H
#define MSPACMAN_SERVTEST_H


#include <cassert>
#include "../src/cliserv/Serv.h"
#include "../src/cliserv/TCPServ.h"
#include <stdlib.h>


class ServTest  {

public:
    void runAllTest(){
        assert( true );
        //if ( true ) throw std::domain_error("test::exception");

        //TCP test
        TCPServ serv;
        serv.createForListen( 8080 );
        serv.receive_();
        char* testBuff = (char*)"** test Buff **";
        serv.send_( testBuff );
        serv.close_();

    }
};


#endif //MSPACMAN_SERVTEST_H
