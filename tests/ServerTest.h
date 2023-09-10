//
// Created by Bill on 9/10/2023.
//

#ifndef MSPACMAN_SERVERTEST_H
#define MSPACMAN_SERVERTEST_H


#include "../src/UDPServ.h"
#include "../src/Server.h"
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <cassert>


void constructTest(){

    // ******** LOGIN TEST
        // login as Ghost
        Board* board = new Board();
        Server server( board );

        char in[BUFFSIZE]={'L','G',0};
            int id= server.command( in )[0];

        assert( (id >= 0) );

        Controller* CMob = board->getMobFrom( id );
        assert(  ( CMob->isGhost()==true ) );

        // login as Pac
        in[0]='L'; in[1]='P'; in[2]=0;
        id= server.command( in )[0];

        assert( (id >= 0) );

        CMob = board->getMobFrom( id );
        assert(  ( CMob->isGhost()==false ) );





    }
    void sendTest(){

    }
    void receiveTest(){

    }


//assert(40 == b.edgeChessPosition(30, false));


#endif //MSPACMAN_SERVERTEST_H
