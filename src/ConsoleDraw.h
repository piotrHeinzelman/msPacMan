//
// Created by Bill on 8/28/2023.
//

#ifndef MSPACMAN_CONSOLEDRAW_H
#define MSPACMAN_CONSOLEDRAW_H


#include <iostream>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

// • ─ ━ │ ┃ ┄ ┅ ┆ ┇ ┈ ┉ ┊ ┋ ┌ ┍ ┎ ┏ ┐ ┑ ┒ ┓ └ ┕ ┖ ┗
// ┘ ┙ ┚ ┛ ├ ┝ ┞ ┟ ┠ ┡ ┢ ┣ ┤ ┥ ┦ ┧ ┨ ┩ ┪ ┫ ┬ ┭ ┮ ┯ ┰ ┱ ┲ ┳
// ┴ ┵ ┶ ┷ ┸ ┹ ┺ ┻ ┼ ┽ ┾ ┿ ╀ ╁ ╂ ╃ ╄ ╅ ╆ ╇ ╈ ╉ ╊ ╋ ╌ ╍ ╎ ╏
// ═ ║ ╒ ╓ ╔ ╕ ╖ ╗ ╘ ╙ ╚ ╛ ╜ ╝ ╞ ╟ ╠ ╡ ╢ ╣ ╤ ╥ ╦ ╧ ╨ ╩ ╪ ╫ ╬ ╭ ╮ ╯ ╰
// ▀ ▄ ▌ █ ▐ ░ ▒ ▓ ■ □ ▪ ▫ ▴ ▸ ▾ ◂ ◊ ○ ◌ ☺ ☻ ☼ ♪ ♥ ♥

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

        COORD cursor = {x, y};
        DWORD written;
                SetConsoleTextAttribute( hout, (WORD) 0x0F ); // White
        HWND window = GetConsoleWindow();

        LPPAINTSTRUCT lpp;
        BeginPaint(window,lpp);
        DWORD dwWritten = 0;
        const char chars[] = "122333";
        WriteConsoleOutputCharacter(hout, cs, strlen(cs), cursor, &dwWritten);


    }


    void WritcheChar2(SHORT x, SHORT y, const char* chr ,int len) {
/*
        BOOL WINAPI SetConsoleTextAttribute(
                HANDLE hConsoleOutput,
                WORD wAttributes
        );
*/
        SetConsoleTextAttribute( hout, (WORD) 0x02 );


        COORD cursor = {x, y};
        DWORD written;

        DWORD dwWritten = 0;
        WriteConsoleOutputCharacter(hout, chr, len, cursor, &dwWritten);
        SetConsoleTextAttribute( hout, (WORD) 0x0F );


/*
        COORD cursor = {x, y};
        DWORD written;

        DWORD dwWritten = 0;
        const char chars[] = "122333";



        PCONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hout, csbi);

        printf( "\n\n%s" , csbi->dwMaximumWindowSize.X );

        WORD attribute = FOREGROUND_RED ;
        _CHAR_INFO charInfo { 0x10 , FOREGROUND_RED };

        FillConsoleOutputAttribute( hout, attribute, 1, cursor, &dwWritten );





/*
        typedef struct _CONSOLE_SCREEN_BUFFER_INFO
        {
            COORD dwSize;
            COORD dwCursorPosition;
            WORD wAttributes;
            SMALL_RECT srWindow;
            COORD dwMaximumWindowSize;
        } CONSOLE_SCREEN_BUFFER_INFO;

        BOOL WINAPI GetConsoleScreenBufferInfo(
                _In_  HANDLE                      hConsoleOutput,
                _Out_ PCONSOLE_SCREEN_BUFFER_INFO lpConsoleScreenBufferInfo
        );
*/








        //::WriteConsoleOutputAttribute(h, &attribute, 1, here, &written);
        //::WriteConsoleOutputCharacterA(h, symbol, 1, here, &written);
        //SetConsoleCursorPosition(2,2);
        // WriteConsole()
    }

/*
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
*/
 //https://stackoverflow.com/questions/9274745/using-writeconsoleoutputcharacter-and-setconsoletextattribute
};


#endif //MSPACMAN_CONSOLEDRAW_H
