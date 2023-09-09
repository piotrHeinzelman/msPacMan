//
// Created by Bill on 9/8/2023.
//

#include <iostream>
#include "Controller.h"


bool Controller::isGhost() {
    return ghost;
}

Controller::Controller( const std::string &name , bool ghost ) {
    Controller::name = name;
    Controller::ghost = ghost;
}


DIRECT Controller::getDirection() const { return direction; }
void Controller::setDirection(DIRECT nextDirection) { Controller::direction = direction; }

DIRECT Controller::getNextDirection() const  { return nextDirection; }
void Controller::setNextDirection(DIRECT nextDirection) {
    setNextDirection(nextDirection);
    if ( getDirection()==DIRECT::STOP ) setDirection(nextDirection);
    if ( parent->getBridge()->isW()){
        if (nextDirection==DIRECT::E || nextDirection==DIRECT::W  ) { setDirection(nextDirection);}
    } else {
        if (nextDirection==DIRECT::N || nextDirection==DIRECT::S  ) { setDirection(nextDirection);}
    }

    Controller::direction = direction; }

void Controller::IamOnEdge() {
    //std::cout << "where should I go now?";
}

void Controller::setParent(Mob * parent) {
    this->parent = parent;
}
