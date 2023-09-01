//
// Created by Bill on 8/28/2023.
//

#ifndef MSPACMAN_CONSOLEDRAW_H
#define MSPACMAN_CONSOLEDRAW_H


#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <valarray>

/*

// • ─ ━ │ ┃ ┄ ┅ ┆ ┇ ┈ ┉ ┊ ┋ ┌ ┍ ┎ ┏ ┐ ┑ ┒ ┓ └ ┕ ┖ ┗
// ┘ ┙ ┚ ┛ ├ ┝ ┞ ┟ ┠ ┡ ┢ ┣ ┤ ┥ ┦ ┧ ┨ ┩ ┪ ┫ ┬ ┭ ┮ ┯ ┰ ┱ ┲ ┳
// ┴ ┵ ┶ ┷ ┸ ┹ ┺ ┻ ┼ ┽ ┾ ┿ ╀ ╁ ╂ ╃ ╄ ╅ ╆ ╇ ╈ ╉ ╊ ╋ ╌ ╍ ╎ ╏
// ═ ║ ╒ ╓ ╔ ╕ ╖ ╗ ╘ ╙ ╚ ╛ ╜ ╝ ╞ ╟ ╠ ╡ ╢ ╣ ╤ ╥ ╦ ╧ ╨ ╩ ╪ ╫ ╬ ╭ ╮ ╯ ╰
// ▀ ▄ ▌ █ ▐ ░ ▒ ▓ ■ □ ▪ ▫ ▴ ▸ ▾ ◂ ◊ ○ ◌ ☺ ☻ ☼ ♪ ♥ ♥



  SetConsoleTextAttribute( hout, attrib );
  chr = charCode;
  SetConsoleCursorPosition(hout,{x,y});
  std::cout << chr;
  //WriteConsoleOutputCharacter(hout, &chr, 1, {x,y}, &dwWritten);

  0x00 czarny  0x08+0x00 szary
  0x01 blue    0x08+0x01 hard blue
  0x02 green   0x08+0x02 hard green
  0x03 turkus
  0x04 red
  0x05 fuksja ?
  0x06 zolty
  0x07 bialy  0x07+0x08 =0x0f mocno biały
  */



class ConsoleDraw {

private:
    HANDLE hout;
    char chr[2]="";
    DWORD dwWritten;
    COORD cursor;


public:
    ConsoleDraw();  // konstruktor klasy, qaczy z obiektem Konsola
    void WriteColourChar(SHORT x, SHORT y, char charCode ,DWORD attrib=0x07 +0x00 );  // rysuje znak
    void WriteColourChar( COORD cursor, char charCode ,DWORD attrib=0x07 +0x00 );     // rysuje znak











/*

    void WriteCharAt_OFF(SHORT x, SHORT y , const char* cs){

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


    void WritcheChar2_OFF(SHORT x, SHORT y, const char* chr , int len) {
        //SetConsoleTextAttribute( hout, (WORD) 0x02 );
        DWORD written;
        WriteConsoleOutputCharacter(hout, chr, len, {x,y}, &dwWritten);


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
  //  }

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
        WriteCharAt_OFF(0, 4, ary5);
    }
*/
 //https://stackoverflow.com/questions/9274745/using-writeconsoleoutputcharacter-and-setconsoletextattribute
};





#endif //MSPACMAN_CONSOLEDRAW_H
