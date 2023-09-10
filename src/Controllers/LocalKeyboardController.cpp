//
// Created by Bill on 9/9/2023.
//

#include "LocalKeyboardController.h"

LocalKeyboardController::LocalKeyboardController( const std::string &name , bool ghost, Bridge* bridge )
        : Controller( name , ghost , bridge ) {
}


void LocalKeyboardController::IamOnEdge() {
    //NOP
}

void LocalKeyboardController::checkTick(Controller *mob) {
    DIRECT activeDirection=DIRECT::STOP;
    DIRECT d;
    if (GetKeyState(VK_NUMPAD8   ) < 0 ) { d=DIRECT::N; if (d != activeDirection ) { activeDirection=d; setNextDirection( d ); }}
    if (GetKeyState(VK_NUMPAD5 ) < 0 ) { d=DIRECT::S; if (d != activeDirection ) { activeDirection=d; setNextDirection( d ); }}
    if (GetKeyState(VK_NUMPAD4 ) < 0 ) { d=DIRECT::W; if (d != activeDirection ) { activeDirection=d; setNextDirection( d ); }}
    if (GetKeyState(VK_NUMPAD6) < 0 ) { d=DIRECT::E; if (d != activeDirection ) { activeDirection=d; setNextDirection( d ); }}
}


