//
// Created by Bill on 8/31/2023.
//
#include <iostream>
#include "Keyb.h"
#include "DIRECT.h"

Keyb::Keyb() {}


DIRECT Keyb::read() {
/*
    int c;
    switch((c=getch())) {
        case KEY_UP:
            std::cout << "Up\n";//key up
            break;
        case KEY_DOWN:
            std::cout << "Down\n";//
            break;
        case KEY_LEFT:
            std::cout << "Left\n";//key up
            break;
        case KEY_RIGHT:
            std::cout << "Right\n";//key up
            break;
        default:
            //cout << endl << "null" << endl;  // not arrow
            break;
    }
*/





    if (GetAsyncKeyState(VK_UP) < 0) { return DIRECT::N; }
    if (GetAsyncKeyState(VK_DOWN) < 0) { return DIRECT::S; }
    if (GetAsyncKeyState(VK_RIGHT) < 0) { return DIRECT::E; }
    if (GetAsyncKeyState(VK_LEFT) < 0) { return DIRECT::W; }

    return DIRECT::STOP;
};
