//
// Created by Bill on 8/31/2023.
//

#ifndef MSPACMAN_KEYB_H
#define MSPACMAN_KEYB_H

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#include <winsock2.h>
#include <Windows.h>
#include <wchar.h>
#include "DIRECT.h"
#include <conio.h>
//https://learn.microsoft.com/en-us/windows/win32/learnwin32/keyboard-input#miscellaneous-keyboard-messages

class Keyb {

public:
    Keyb();

    DIRECT read();

};




#endif //MSPACMAN_KEYB_H
