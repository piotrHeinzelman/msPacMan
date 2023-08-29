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

        // draw board

        Board board;
              board.Bridges;

        char buf[24]={0};

        for (int j=0;j<240;j+=20) {
            for (int i = 0; i < 19; i++, i++) {
                if (board.Bridges[i + 1 + j] == ' ') {
                    buf[i] = 'o'; buf[i + 1] = ' ';
                } else {
                    buf[i] = 'o'; buf[i + 1] = board.Bridges[i + 1 + j];
                }
            }
            printf("%s \n"  , buf);

            for (int i = 0; i < 19; i++, i++) {
                if (board.Bridges[i + 10+ j] == ' ') {
                    buf[i] = ' '; buf[i + 1] = ' ';
                } else {
                    buf[i] = board.Bridges[i + 10 + j]; buf[i + 1] = ' ';
                }
            }
            printf("%s \n"  , buf);
        }
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
        }

        ConsoleDraw cd;

        for (int i=0;i<19*5;i++){
            cd.WriteColourChar( i, 1 , i+176  );
        }
        cd.WriteColourChar( 3,3 ,176   );

        Board b;
        b.drawBridge( 1);
        b.drawBridge( 3);
        b.drawBridge( 5);
        b.drawBridge( 21);



        return;


        b.prepare();
        b.BoardTick();


        b.drawBridge( 30);
        b.drawBridge( 187);


    }


};


#endif //MSPACMAN_BOARDTEST_H
