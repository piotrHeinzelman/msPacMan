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

//https://stackoverflow.com/questions/9274745/using-writeconsoleoutputcharacter-and-setconsoletextattribute


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
    HANDLE getHandle();


};





#endif //MSPACMAN_CONSOLEDRAW_H
