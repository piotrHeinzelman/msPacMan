//
// Created by Bill on 8/27/2023.
//

#ifndef MSPACMAN_BOARDTEST_H
#define MSPACMAN_BOARDTEST_H


#include <cstdio>
#include "../src/Board.h"

#include <windows.h>



class BoardTest {
public:
    BoardTest(){
        Board board;
              board.Bridges;

        char buf[20];

        for (int j=0;j<260;j+=20) {
            for (int i = 0; i < 20; i++, i++) {
                if (board.Bridges[i + 1 + j] == ' ') {
                    buf[i] = 'o'; buf[i + 1] = ' ';
                } else {
                    buf[i] = 'o'; buf[i + 1] = '-';
                }
            }
            printf("%s\n" , buf);
        }
    }
};


#endif //MSPACMAN_BOARDTEST_H
