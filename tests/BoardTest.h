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
    BoardTest(){

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


        graph();


    }



    void graph(){

        void initgraph(int far *graphdriver, int far *graphmode, char far *pathtodriver);
        void setgraphmode(int VGAHi);
         //        Użyteczne jedynie  i IBM8514Lo
        sleep(5);
    }


};


#endif //MSPACMAN_BOARDTEST_H
