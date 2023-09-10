//
// Created by Bill on 9/9/2023.
//

#include "GhostAutoController.h"

GhostAutoController::GhostAutoController( const std::string &name , bool ghost, Bridge* bridge )
        : Controller( name , ghost , bridge ) {
}


void GhostAutoController::IamOnEdge() {
        ghostIntel++;
        if (ghostIntel%10==3) direction= DIRECT::N ;
        if (ghostIntel%10==7) direction= DIRECT::S ;
        if (ghostIntel%11==4) direction= DIRECT::W ;
        if (ghostIntel%15==2) direction= DIRECT::E ;
}

void GhostAutoController::checkTick(Controller *mob) {
    // NOP
}


