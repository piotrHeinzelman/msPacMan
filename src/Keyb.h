//
// Created by Bill on 8/31/2023.
//

#ifndef MSPACMAN_KEYB_H
#define MSPACMAN_KEYB_H

#include <winsock2.h>
#include <Windows.h>
#include <wchar.h>
#include "DIRECT.h"
//https://learn.microsoft.com/en-us/windows/win32/learnwin32/keyboard-input#miscellaneous-keyboard-messages

class Keyb {

public:
    Keyb();

    DIRECT read();

};




#endif //MSPACMAN_KEYB_H
