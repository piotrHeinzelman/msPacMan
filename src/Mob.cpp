//
// Created by Bill on 8/28/2023.
//

#include <iostream>
#include "Mob.h"
#include "Board.h"

Mob::Mob(int id, std::string name , Board* board,  bool ghost ) {
    this->id=id;
    this->step=0;
    this->direction=DIRECT::STOP;
    this->nextDirection=DIRECT::STOP;
    this->board=board;
    this->ghost=ghost;
}


void Mob::setStep( int step ) { this->step = step; }
int  Mob::getStep(){ return this->step; };
int Mob::getId() { return id; }

DIRECT Mob::getDirection() { return direction; }
DIRECT Mob::getNextDirection() { return nextDirection; }

void Mob::setDirection(DIRECT direction){ nextDirection = direction; };
void Mob::setNextDirection(DIRECT nextDirection){ nextDirection = nextDirection; };

int  Mob::getBridge()  { return bridge; }
void Mob::setBridge( int bridge ) { this->bridge = bridge; }





/*
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

 void Mob::_atEdge() {
  //  direction = ((Board*)board)->atEdge(id , direction , nextDirection );
}

 */

void Mob::stepN( bool isW ){ if(!isW){ if (step == 0    ) { board->moveMeToNextBridge(id, direction ); } else { step--; }}};
void Mob::stepS( bool isW ){ if(!isW){ if (step == STEPS) { board->moveMeToNextBridge(id, direction ); } else { step++; }}};
void Mob::stepE( bool isW ){ if( isW){
        //std::cout <<"\n\nid"<<id<<", pos: " << step <<", dir:"<<direction<<"  \n";
        if (step == STEPS) {
            board->moveMeToNextBridge(id, direction );
        } else { step++; }}};
void Mob::stepW( bool isW ){ if( isW){ if (step == 0    ) { board->moveMeToNextBridge(id, direction ); } else { step--; }}}







// getters / setters
void Mob::addPoint( int points ){ this->points += points; }
void Mob::addPower( int power ){ this->power=power; }
int Mob::getPower(){ return this->power; }
int Mob::getPoints(){ return this->points; }
bool Mob::isGhost(){ return this->ghost; }














