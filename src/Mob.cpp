//
// Created by Bill on 8/28/2023.
//

#include <iostream>
#include "Mob.h"
#include "Board.h"

Mob::Mob(int id, std::string name , Board* board,  bool ghost ) {
    this->id=id;
    this->positionOnBridge=0;
    this->direction=DIRECT::STOP;
    this->nextDirection=DIRECT::STOP;
    this->board=board;
    this->ghost=ghost;
    //this->parentBoard = parent;
}

void Mob::setPositionOnBridge(int position) {
    positionOnBridge=position;
    if (position==STOP) direction=STOP;
}

unsigned short Mob::getId() { return id;}

int Mob::getPositionOnBridge() {
    return positionOnBridge;
}

void Mob::step() {
    int numBridge=board->activeBridges[id];
    bool isW;
    if ((numBridge&0x01)==1) { isW=true; } else {isW=false;}

    // move Mob
    switch ( direction ) {
        case DIRECT::N: stepN(isW); break;
        case DIRECT::W: stepW(isW); break;
        case DIRECT::S: stepS(isW); break;
        case DIRECT::E: stepE(isW); break;
    }
    board->drawOneMob( id );
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

DIRECT Mob::getDirection(){
    return this->direction;
}

void Mob::stepN( bool isW ){ if(!isW){ if (positionOnBridge==0    ) { this->board->moveMeToNextBridge(id, direction ); } else { positionOnBridge--; }}};
void Mob::stepS( bool isW ){ if(!isW){ if (positionOnBridge==STEPS) { this->board->moveMeToNextBridge(id, direction ); } else { positionOnBridge++; }}};
void Mob::stepE( bool isW ){ if( isW){ if (positionOnBridge==STEPS) { this->board->moveMeToNextBridge(id, direction ); } else { positionOnBridge++; }}};
void Mob::stepW( bool isW ){ if( isW){ if (positionOnBridge==0    ) { this->board->moveMeToNextBridge(id, direction ); } else { positionOnBridge--; }}};


