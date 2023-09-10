//
// Created by Bill on 8/28/2023.
//

#include <iostream>
#include "Mob.h"


Mob::Mob() {
    lives=5;
}


// getters / setters
void Mob::addPoint( unsigned int points ){ this->points += points; }
void Mob::addPower( int power ){ this->power=power; }
int  Mob::getPower(){ return this->power; }
int  Mob::getPoints(){ return this->points; }


void Mob::grabEnergy() {
    if ( power<0) { power=0; }
    if ( power>0 ) { power-=4; }
}

int Mob::getLives() { return lives; }
void Mob::setLives(int lives) { Mob::lives = lives; }

int Mob::gameOver() { return lives==0; }

