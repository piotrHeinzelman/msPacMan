//
// Created by Bill on 8/28/2023.
//

#include "Mob.h"

Mob::Mob(int id, std::string name ) {
    this->id=id;
    //this->parentBoard = parent;
}

void Mob::setPosition(int position) {
    positionOnBridge=position;
    if (position==STOP) direction=STOP;
}

unsigned short Mob::getId() { return id;}

int Mob::getPosition() {
    return positionOnBridge;
}

void Mob::step() {
    switch (direction) {
        case N: case W: if ( positionOnBridge!=STEPS ) { positionOnBridge++; } else { _atEdge(); } break;
        case S: case E: if ( positionOnBridge!=0 ) { positionOnBridge--; } else { _atEdge(); } break;
        case STOP: _atEdge(); break;
    }
}

void Mob::setDirection(DIRECT direction){
    nextDirection = direction;
};

void Mob::_atEdge() {
    //direction = ((Board*)parentBoard)->atEdge(id , direction , nextDirection );
}