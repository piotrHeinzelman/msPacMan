//
// Created by Bill on 8/27/2023.
//

#ifndef MSPACMAN_BOARDTEST_H
#define MSPACMAN_BOARDTEST_H




#include <cstdio>
#include "../src/Board.h"

#include <windows.h>

#include "../_lib/graphics.h"
//#pragma comment (lib, "Ws2_32.lib")


class BoardTest {
public:



    void BoardPreview(){


    }


    void BridgeTest() {

        if (false ) {
            char Buff[255];

            ConsoleDraw cd;
            cd.WriteCharAt(3, 3, "X");

            for (unsigned int i = 0x1; i < 0x200; i++) {
                Buff[i] = i;
                cd.WritcheChar2(4, 4, Buff, 0x200);
            }
            for (unsigned int i = 0x201; i < 0x400; i++) {
                Buff[i] = i;
                cd.WritcheChar2(5, 5, Buff, 0x200);
            }

            cd.WriteColourChar(2,2,0x40  );
            cd.WriteColourChar(3,3,0x40,0x08);


            // ************

            for (int i=0;i<19*5;i++){
                cd.WriteColourChar( i, 1 , i+176  );
            }
            cd.WriteColourChar( 3,3 ,176   );
        }

        ConsoleDraw cd;
        cd.WriteColourChar( 0,0,176 );
      /*  cd.WriteColourChar( 0,2,176 );
        cd.WriteColourChar( 2,0,176 );
        cd.WriteColourChar( 2,2,176 );

        cd.WriteColourChar( 18,0,176 );
        cd.WriteColourChar( 18,23,176 );

*/
        Board b;
        b.drawBridge(1);
        b.drawBoard();
  /*      b.drawBridge( 1);
        b.drawBridge( 3);
        b.drawBridge( 5);
        b.drawBridge( 7);
        b.drawBridge( 11);
        b.drawBridge( 13);
        b.drawBridge( 15);
        b.drawBridge( 17);




        b.drawBridge( 21);
        b.drawBridge( 37);
        b.drawBridge( 235);
*//*
        b.drawBridge( 10);
        b.drawBridge( 28);
        b.drawBridge( 30);
        b.drawBridge( 210);
        b.drawBridge( 228);
        /*     b.drawBridge( 54);
             b.drawBridge( 14);
             b.drawBridge( 228);
             b.drawBridge( 28);

    */ /*        b.drawBridge( 3);
             b.drawBridge( 5);
             b.drawBridge( 21);
     */







        return;


        b.prepare();
        b.BoardTick();


        b.drawBridge( 30);
        b.drawBridge( 187);


    }


};


#endif //MSPACMAN_BOARDTEST_H
