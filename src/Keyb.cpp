//
// Created by Bill on 8/31/2023.
//
#include <iostream>
#include "Keyb.h"
#include "DIRECT.h"

Keyb::Keyb() {}


DIRECT Keyb::read() {

    if ( GetKeyState ('A') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
    {
      return DIRECT::W;
    }
    if ( GetKeyState ('S') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
    {
        return DIRECT::S;
    }
    if ( GetKeyState ('D') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
    {
        return DIRECT::E;
    }
    if ( GetKeyState ('W') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
    {
        std::cout<<"w";
        return DIRECT::N;
    }
    return DIRECT::STOP;
};
