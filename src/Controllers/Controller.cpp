//
// Created by Bill on 9/8/2023.
//

#include "Controller.h"



bool Controller::isGhost() {
    return ghost;
}

Controller::Controller( const std::string &name , bool ghost) {
    Controller::name = name;
    Controller::ghost = ghost;
}


DIRECT Controller::getDirection() const { return direction; }
void Controller::setDirection(DIRECT nextDirection) { Controller::direction = direction; }

DIRECT Controller::getNextDirection() const  { return nextDirection; }
void Controller::setNextDirection(DIRECT nextDirection) { Controller::direction = direction; }