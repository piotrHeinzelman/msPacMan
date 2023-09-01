//
// Created by Bill on 8/28/2023.
//

#include <iostream>
#include "Mob.h"


Mob::Mob(int id, std::string name, bool ghost ) {
    this->id=id;
    this->name = name;
    this->direction;
    this->nextDirection;
    this->ghost=ghost;
}

int Mob::getStep() const { return step; }
void Mob::setStep(int step) { Mob::step = step; }
int Mob::getField() const { return field; }
void Mob::setField(int field) { Mob::field = field; }
DIRECT Mob::getDirection() const { return direction; }
void Mob::setDirection(DIRECT direction) { Mob::direction = direction; }



























/*

void Mob::setPositionOnBridge(int position) {
    step=position;
    if (position==STOP) direction=STOP;
}

unsigned short Mob::getId() { return id;}

int Mob::getPositionOnBridge() {
    return step;
}

void Mob::nextStep() {
    int numBridge=parentBoard->activeBridges[id];
    bool isW;
    if ((numBridge&0x01)==1) { isW=true; } else {isW=false;}

    // move Mob
    switch ( this->direction ) {
        case DIRECT::N: stepN(isW); break;
        case DIRECT::W: stepW(isW); break;
        case DIRECT::S: stepS(isW); break;
        case DIRECT::E: stepE(isW); break;
    }
    parentBoard->drawOneMob( id );
}

void Mob::setDirection(DIRECT direction){
    this->nextDirection = direction;
    if ( this->direction==DIRECT::STOP ) { this->direction=direction;}

    //SetConsoleCursorPosition(parentBoard->cdraw.getHandle(),{5,1});
    //std::cout << "direction: " << this->direction << ", nextDirection: " << nextDirection;
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

void Mob::stepE( bool isW ){ if( isW ){ if (step != STEPS) { this->step++; } else { checkNextDirection(); parentBoard->moveMeToNextBridge(id, direction ); } }};


void Mob::stepN( bool isW ){ if(!isW){ if (step != 0 )    { this->step--; } else  { checkNextDirection(); parentBoard->moveMeToNextBridge(id, direction ); }}};
void Mob::stepS( bool isW ){ if(!isW){ if (step != STEPS) { this->step++; } else { checkNextDirection(); parentBoard->moveMeToNextBridge(id, direction ); } }};
void Mob::stepW( bool isW ){ if( isW){ if (step == 0    ) { checkNextDirection(); parentBoard->moveMeToNextBridge(id, direction ); } else { step--; }}};

void Mob::checkNextDirection(){
    int numBridge=parentBoard->activeBridges[id];
    bool isW;
    if ((numBridge&0x01)==1) { isW=true; } else {isW=false;}
    bool fromStart = (( direction==DIRECT::N) || (direction==DIRECT::W));

    int edge = parentBoard->getBridges()->edgeChessPosition(numBridge, fromStart);
    if ( !parentBoard->getBridges()->isExistsWayFromEdge( edge , direction )) { direction=DIRECT::STOP; }
    if ( parentBoard->getBridges()->isExistsWayFromEdge( edge , nextDirection )) { direction=nextDirection; }

}

*/