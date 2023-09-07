//
// Created by Bill on 8/28/2023.
//

#include "ConsoleDraw.h"

ConsoleDraw::ConsoleDraw() {
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hout == INVALID_HANDLE_VALUE) {
        throw std::runtime_error("Console output handle error");
    }

    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(hout, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(hout, &cursorInfo);
}

void ConsoleDraw::WriteColourChar(SHORT x, SHORT y, char charCode , DWORD attrib ) {
    return WriteColourChar( COORD { x, y } , charCode , attrib );
}

void ConsoleDraw::WriteColourChar( COORD cursor, char charCode ,DWORD attrib  ) {
    cursor = { static_cast<SHORT>(cursor.X+3) , static_cast<SHORT>(cursor.Y+3) };
    chr[0] = charCode;
    //SetConsoleTextAttribute( hout, (WORD) 0x0F ); // White
    //SetConsoleCursorPosition( hout , {0,0});
    WriteConsoleOutputCharacter(hout, reinterpret_cast<LPCSTR>(&chr), 1, cursor, &dwWritten);

    /* OK
    chr[0] = charCode;
    SetConsoleTextAttribute( hout, (WORD) 0x0F ); // White

    int x=0;//+3;
    int y=0;//+3;
    COORD dst = { static_cast<SHORT>(x+cursor.X) , static_cast<SHORT>(y+cursor.Y) };
    WriteConsoleOutputCharacter(hout, chr, strlen(chr), dst, &dwWritten);
     */
}

HANDLE ConsoleDraw::getHandle() {
    return hout;
}

void ConsoleDraw::cls(){
        SetConsoleCursorPosition(getHandle(), {0, 0});
        for (int i = -3; i < 70; i++) {
            for (int j = 0; j < 30; j++) {
                WriteColourChar(i, j, ' ', 0);
            }
        }
    }

