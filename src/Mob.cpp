//
// Created by Bill on 8/28/2023.
//

#include <iostream>
#include "Mob.h"
#include "Board.h"

Mob::Mob(int id, std::string name , bool ghost ) {
    this->id=id;
    this->positionOnBridge=0;
    this->direction=DIRECT::STOP;
    this->nextDirection=DIRECT::STOP;
    this->ghost=ghost;
    //this->parentBoard = parent;
}

void Mob::setPosition(int position) {
    positionOnBridge=position;
    if (position==STOP) direction=STOP;
}

unsigned short Mob::getId() { return id;}

int Mob::getPositionOnBridge() {
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

void Mob::addPoint( int points ){
    this->points += points;
}

void Mob::addPower( int power ){
    this->power=power;
}

int Mob::getPower(){
    return this->power;
}

int Mob::getPoints(){
    return this->points;
}

bool Mob::isGhost(){
    return this->ghost;
}