//
// Created by Bill on 8/24/2023.
//

#ifndef MSPACMAN_SERVTEST_H
#define MSPACMAN_SERVTEST_H


#include <cassert>
#include "../src/cliserv/TCPServ.h"
#include "../src/cliserv/Cli.h"
#include <stdlib.h>


class ServTest  {

public:
    void runAllTest(){
        assert( true );
        //if ( true ) throw std::domain_error("test::exception");

        //Serv test  ** UNUSED **
        //Serv s;                 // klasa nadrzedna, default port
        //Serv s80(80);           // klasa nadrzedna, wskazany port

        //TCPServ                 // test konstruktora
        //TCPServ ts80(80);   // wskazany port;



        TCPServ ts;               // domyslny port
        ts.rec();

        //Cli c;


        //TCPServ t;

    //    serv.createForListen( );
    //    serv.receive_();
    //    char* testBuff = (char*)"** test Buff **";
    //    serv.send_( testBuff );


    }
};


#endif //MSPACMAN_SERVTEST_H
