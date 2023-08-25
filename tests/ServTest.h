//
// Created by Bill on 8/24/2023.
//

#ifndef MSPACMAN_SERVTEST_H
#define MSPACMAN_SERVTEST_H


#include <cassert>
#include "../src/cliserv/Serv.h"
#include "../src/cliserv/TCPServ.h"


class ServTest  {

public:
    void runAllTest(){
        assert( true );
        //if ( true ) throw std::domain_error("test::exception");

        //TCP test
        TCPServ serv;
        serv.createForListen();
        serv.receive();

        char* testBuff = (char*)"** test Buff **";
        serv.send( testBuff );
        serv.close();

    }
};


#endif //MSPACMAN_SERVTEST_H
