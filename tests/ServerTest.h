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
            int id1= server.command( in )[0];

        assert( (id1 >= 0) );

        Controller* CMob = board->getMobFrom( id1 );
        assert(  ( CMob->isGhost()==true ) );

        // login as Pac
        in[0]='L'; in[1]='P'; in[2]=0;
        int id2 = server.command( in )[0];

        assert( (id2 >= 0) );

        CMob = board->getMobFrom( id2 );
        assert(  ( CMob->isGhost()==false ) );

    // *************   LOGOUT

        in[0]='O'; in[1]=(char)id2; in[2]=0;
        std::cout << "\nLogout: id(" << id2 << "), " << server.command( in ) << "\n";
        assert( board->getMobFrom( id2 )==0 );


    }



    void sendTest(){

    }
    void receiveTest(){

    }


//assert(40 == b.edgeChessPosition(30, false));


#endif //MSPACMAN_SERVERTEST_H
