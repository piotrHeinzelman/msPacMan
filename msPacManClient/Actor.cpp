#include "Actor.h"

Actor::Actor(){}

void Actor::addPoint( int point ){
    this->points+=point;
}

void Actor::increasePower(){
    this->power += 200;
}
