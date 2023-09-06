//
// Created by Bill on 8/28/2023.
//

#include <iostream>
#include "Mob.h"
#include "Board.h"
#include "Bridge.h"

Mob::Mob(int id, std::string name , Board* board,  bool ghost ) {
    this->id=id;
    this->step=0;
    this->direction=DIRECT::STOP;
    this->nextDirection=DIRECT::STOP;
    this->board=board;
    this->ghost=ghost;
}



int Mob::getId() { return id; }

DIRECT Mob::getDirection() { return direction; }

void Mob::setDirection(DIRECT direction){ this->direction = direction; };
void Mob::setNextDirection(DIRECT nextDirection){ this->nextDirection = nextDirection; if (this->direction==DIRECT::STOP) this->direction=nextDirection; };

Bridge * Mob::getBridge()  { return bridge; }
void Mob::setBridge( Bridge* bridge ) { this->bridge = bridge; }



// getters / setters
void Mob::addPoint( int points ){ this->points += points; }
void Mob::addPower( int power ){ this->power=power; }
int  Mob::getPower(){ return this->power; }
int  Mob::getPoints(){ return this->points; }
bool Mob::isGhost(){ return this->ghost; }

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
        case DIRECT::N : if ( w.n!=nullptr ) { setBridge( w.n ); setStep( STEPS); };  break;
        case DIRECT::W : if ( w.w!=nullptr ) { setBridge( w.w ); setStep( STEPS ); }; break;
        case DIRECT::S : if ( w.s!=nullptr ) { setBridge( w.s ); setStep( 0 ); };  break;
        case DIRECT::E : if ( w.e!=nullptr ) { setBridge( w.e ); setStep( 0 ); };  break;
        default: return;
    }
}


void Mob::checkNextDirection() {
    if ( nextDirection != DIRECT::STOP ){
    Ways w = (step==0) ? getBridge()->getStartWays() : getBridge()->getEndWays();
        if (getBridge()->isW()){
            if ( w.n!=nullptr && nextDirection==DIRECT::N ) setDirection( DIRECT::N );
            if ( w.s!=nullptr && nextDirection==DIRECT::S ) setDirection( DIRECT::S );
        } else {
            if ( w.e!=nullptr && nextDirection==DIRECT::E ) setDirection( DIRECT::E );
            if ( w.w!=nullptr && nextDirection==DIRECT::W ) setDirection( DIRECT::W );
        }
    }
}


