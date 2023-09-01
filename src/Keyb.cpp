//
// Created by Bill on 8/31/2023.
//
#include <iostream>
#include "Keyb.h"

Keyb::Keyb() {}


void Keyb::read() {

    if ( GetKeyState ('A') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
    {
       // std::cout << "PRESS A";
    }
    if ( GetKeyState ('S') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
    {
        //std::cout << "PRESS S";
    }
    if ( GetKeyState ('D') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
    {
        //std::cout << "PRESS D";
    }    if ( GetKeyState ('W') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
    {
        //std::cout << "PRESS W";
    }
}
