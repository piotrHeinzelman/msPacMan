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

void Mob::setDirection(DIRECT direction){ this->direction = direction; };
void Mob::setNextDirection(DIRECT nextDirection){ this->nextDirection = nextDirection;  };

int  Mob::getBridge()  { return bridge; }
void Mob::setBridge( int bridge ) { this->bridge = bridge; }



// getters / setters
void Mob::addPoint( int points ){ this->points += points; }
void Mob::addPower( int power ){ this->power=power; }
int Mob::getPower(){ return this->power; }
int Mob::getPoints(){ return this->points; }
bool Mob::isGhost(){ return this->ghost; }

std::set<DIRECT> & Mob::getExits() { return exits; }


bool Mob::isW() const     { return isW_; }
void Mob::isW( bool isW ) { isW_ = isW; }



bool Mob::isGoForwart() const { return goForwart; }

void Mob::setGoForwart(bool goForwart) { Mob::goForwart = goForwart; }













