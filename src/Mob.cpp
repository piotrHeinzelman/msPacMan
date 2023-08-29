//
// Created by Bill on 8/28/2023.
//

#include <iostream>
#include "Mob.h"
#include "Board.h"

Mob::Mob(int id, std::string name ) {
    this->id=id;
    this->positionOnBridge=0;
    this->direction=DIRECT::STOP;
    this->nextDirection=DIRECT::STOP;
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
    //std::cout << "\nid:"<<id<< ", pos:"<<positionOnBridge << "\n\n";
    switch ( direction ) {
        case DIRECT::N:
        case DIRECT::E:
              if ( positionOnBridge!=STEPS ) { positionOnBridge++; } else { _atEdge(); } break;
        case DIRECT::S:
        case DIRECT::W:
              if ( positionOnBridge!=0 ) { positionOnBridge--; } else { _atEdge(); }; break;
        case DIRECT::STOP: _atEdge();
        default: break;
    }
}

void Mob::setDirection(DIRECT direction){
    nextDirection = direction;
    if  ( this->direction==DIRECT::STOP ) this->direction=direction;
};

void Mob::_atEdge() {
    direction = ((Board*)parent)->atEdge(id , direction , nextDirection );
}

void Mob::setParent( Board *parent ) {
    this->parent=parent;
}