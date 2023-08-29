//
// Created by Bill on 8/28/2023.
//

#ifndef MSPACMAN_CONSOLEDRAW_H
#define MSPACMAN_CONSOLEDRAW_H


#include <iostream>
#include <windows.h>
#include <string.h>
#include <stdlib.h>



class ConsoleDraw {

private:
    HANDLE hout;

public:
    ConsoleDraw() {
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        hout = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hout == INVALID_HANDLE_VALUE) {
            throw std::runtime_error("Console output handle error");
        }
    }
    void WriteCharAt(SHORT x, SHORT y , const char* cs){

        DWORD dwWritten = 0;
        COORD cursor = {x, y};
        //const char cs[] = "122333";
        WriteConsoleOutputCharacter(hout, cs, strlen(cs), cursor, &dwWritten);
    }


    drawW( SHORT x,SHORT y ){
        char *ary1 = "## ### ##";
        char *ary2 = "#   #   #";
        char *ary3 = "         ";
        char *ary4 = "#   #   #";
        char *ary5 = "## ### ##";

        WriteCharAt(0, 0, ary1);
        WriteCharAt(0, 1, ary2);
        WriteCharAt(0, 2, ary3);
        WriteCharAt(0, 3, ary4);
        WriteCharAt(0, 4, ary5);
    }


};


#endif //MSPACMAN_CONSOLEDRAW_H
