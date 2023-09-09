//
// Created by Bill on 8/28/2023.
//

#include <iostream>
#include "Mob.h"


Mob::Mob(int id , Controller* controller , Board* board ) {
    this->id=id;
    this->controller=controller;
    this->step=0;
    this->board=board;
    this->lives=5;
}



DIRECT Mob::getDirection() { return controller->getDirection(); }

void Mob::setDirection(DIRECT direction){ this->controller->setDirection( direction ); };
void Mob::setNextDirection(DIRECT nextDirection){
    this->controller->setNextDirection(nextDirection);
    if (this->controller->getDirection()==DIRECT::STOP) this->controller->setDirection(nextDirection);
    if (this->getBridge()->isW()){
        if (nextDirection==DIRECT::E || nextDirection==DIRECT::W  ) { this->controller->setDirection(nextDirection);}
    } else {
        if (nextDirection==DIRECT::N || nextDirection==DIRECT::S  ) { this->controller->setDirection(nextDirection);}
    }
};






Bridge * Mob::getBridge()  { return bridge; }
void Mob::setBridge( Bridge* bridge ) { this->bridge = bridge; }



// getters / setters
void Mob::addPoint( u_long points ){ this->points += points; }
void Mob::addPower( int power ){ this->power=power; }
int  Mob::getPower(){ return this->power; }
int  Mob::getPoints(){ return this->points; }
bool Mob::isGhost(){ return this->controller->isGhost(); }

std::set<DIRECT> & Mob::getExits() { return exits; }

int Mob::getStep() const { return step; }

void Mob::setStep( int step ) {
    if ( step>STEPS ) {step=STEPS;}
    if ( step<0 )     {step=0;}
    this->step = step;
}

void Mob::gotoNextStep() {
    //if (id==4) { std::cout<<"Step:"<<getStep()<<", Bridge"<<getBridge()->getCenterPoint().X<<"\n"; }
    if (  getStep()==0 || getStep()==STEPS ) {
        checkNextDirection();
        Bridge* in = getBridge();
        if ( getStep()==0 ) {   //na poczatku
                                gotoNextBridge(  getDirection() , getBridge()->getStartWays() );
                                // jeśli była zmiana
                                if ( getBridge()!=in ) return;
                            }
        else                {   gotoNextBridge(  getDirection() , getBridge()->getEndWays()   );
                                if ( getBridge()!=in ) return;
                            }
    }


    if ( getBridge()->isW() ) {
        if ( getDirection()==DIRECT::E ) { setStep(1+getStep()) ; }
        if ( getDirection()==DIRECT::W ) { setStep(getStep()-1) ; }
    } else {
        if ( getDirection()==DIRECT::N ) { setStep(getStep()-1) ; }
        if ( getDirection()==DIRECT::S ) { setStep(1+getStep()) ; }
    }

}



void Mob::gotoNextBridge(  DIRECT dir , Ways w ) {
    switch( dir ){
        case DIRECT::N : if ( w.n!=nullptr ) { setBridge( (Bridge*)w.n ); setStep( STEPS); };  break;
        case DIRECT::W : if ( w.w!=nullptr ) { setBridge( (Bridge*)w.w ); setStep( STEPS ); }; break;
        case DIRECT::S : if ( w.s!=nullptr ) { setBridge( (Bridge*)w.s ); setStep( 0 ); };  break;
        case DIRECT::E : if ( w.e!=nullptr ) { setBridge( (Bridge*)w.e ); setStep( 0 ); };  break;
        default: return;
    }
}


void Mob::checkNextDirection() {
    if ( this->controller->getNextDirection() != DIRECT::STOP ){
        Ways w = (step==0) ? getBridge()->getStartWays() : getBridge()->getEndWays();
        if (getBridge()->isW()){
            if ( w.n!=nullptr && this->controller->getNextDirection()==DIRECT::N ) setDirection( DIRECT::N );
            if ( w.s!=nullptr && this->controller->getNextDirection()==DIRECT::S ) setDirection( DIRECT::S );
        } else {
            if ( w.e!=nullptr && this->controller->getNextDirection()==DIRECT::E ) setDirection( DIRECT::E );
            if ( w.w!=nullptr && this->controller->getNextDirection()==DIRECT::W ) setDirection( DIRECT::W );
        }
    }
}

COORD Mob::getAvatarPosition() {
    COORD startPoint = getBridge()->getStartPoint();
    int mobX = startPoint.X;
    int mobY = startPoint.Y;
// correction  point
    if (bridge->isW()) {
        mobX += getStep();
    } else {
        if (getStep() > 1) mobY++;
        if (getStep() > 4) mobY++;
    }
    return COORD {static_cast<SHORT>(mobX),static_cast<SHORT>(mobY) };
}

void Mob::grabEnergy() {
    if ( power<0) { power=0; }
    if ( power>0 ) { power-=4; }
}

int Mob::getLives() { return lives; }
void Mob::setLives(int lives) { Mob::lives = lives; }

int Mob::gameOver() {
    return 0;
}

int Mob::getId() const { return id; }
