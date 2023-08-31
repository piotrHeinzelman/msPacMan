//
// Created by Bill on 8/28/2023.
//

#include "ConsoleDraw.h"

ConsoleDraw::ConsoleDraw() {
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hout == INVALID_HANDLE_VALUE) {
        throw std::runtime_error("Console output handle error");
    }
}

void ConsoleDraw::WriteColourChar(SHORT x, SHORT y, char charCode , DWORD attrib ) {
    return WriteColourChar( COORD { x, y } , charCode , attrib );
}

void ConsoleDraw::WriteColourChar( COORD cursor, char charCode ,DWORD attrib  ) {
    chr[0] = charCode;
    SetConsoleTextAttribute( hout, (WORD) 0x0F ); // White

    COORD dst = { static_cast<SHORT>(3+cursor.X) , static_cast<SHORT>(3+cursor.Y) };
    WriteConsoleOutputCharacter(hout, chr, strlen(chr), dst, &dwWritten);
}
