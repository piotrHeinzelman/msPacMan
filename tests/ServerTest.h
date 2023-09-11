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

    if (true) {

        // ******** LOGIN TEST
        // login as Ghost
        Board *board = new Board();
        board->prepare();
        board->drawBoard();
        Server server(board);

        std::string in = "LG                              ";
        server.command(in);
        int id1 = in[0];
        assert((id1 >= 0));
        Controller *GhostMob = board->getMobFrom(id1);
        assert((GhostMob->isGhost() == true));

        // login as Pac
        in[0] = 'L';
        in[1] = 'P';
        in[2] = 0;
        server.command(in);
        int id2 = in[0];
        assert((id2 >= 0));
        Controller *PacMob = board->getMobFrom(id2);
        assert((PacMob->isGhost() == false));





        // *************   Mobiles
        PacMob->setStep(0);
        PacMob->setBridge(board->getBridgeFrom(3));
        GhostMob->setStep(5);
        GhostMob->setBridge(board->getBridgeFrom(5));



        // get Mobiles
        in[0] = 'M';
        in[1] = 0;
        in[2] = 0;
        server.command(in);
        int SecondMobId = in[5];
        Controller *TestMob = board->getMobFrom(SecondMobId);
        assert(in[4] == ((char) (TestMob->isGhost()) ? 'G' : '?'));
        assert(in[5] == TestMob->getId());
        assert(in[6] == TestMob->getBridge()->getBridgeNum());
        assert(in[7] == TestMob->getStep());
        std::cout << "\nMobiles: " << in << "\n";
        // --------  mobiles


        std::string mString = {"C" + in};




        // *************   LOGOUT

        in[0] = 'O';
        in[1] = 1;
        in[2] = 0;
        server.command(in);
        std::cout << "\nLogout: id(" << in[1] << ")\n";
        assert(board->getMobFrom(1) == 0);


        // create Mobiles from String
        //server.command( mString );

        // & test
        in[0] = 'M';
        in[1] = 0;
        in[2] = 0;
        server.command(in);
        std::cout << "\nMobiles: " << in << "\n";

        in[0] = 'D';
        in[1] = 0;
        in[2] = 0;
        server.command(in);
        std::cout << "\nDots: " << in << "\n";

    }
}



    void sendTest(){

    }
    void receiveTest(){

    }


//assert(40 == b.edgeChessPosition(30, false));


#endif //MSPACMAN_SERVERTEST_H
