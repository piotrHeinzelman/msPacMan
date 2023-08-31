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








        return;
    }


};


#endif //MSPACMAN_BOARDTEST_H
