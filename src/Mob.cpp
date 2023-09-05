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
void Mob::setNextDirection(DIRECT nextDirection){ this->nextDirection = nextDirection;  };

Bridge * Mob::getBridge()  { return bridge; }
void Mob::setBridge( Bridge* bridge ) { this->bridge = bridge; }



// getters / setters
void Mob::addPoint( int points ){ this->points += points; }
void Mob::addPower( int power ){ this->power=power; }
int Mob::getPower(){ return this->power; }
int Mob::getPoints(){ return this->points; }
bool Mob::isGhost(){ return this->ghost; }

std::set<DIRECT> & Mob::getExits() { return exits; }


bool Mob::isGoForwart() const { return goForwart; }

void Mob::setGoForwart(bool goForwart) { Mob::goForwart = goForwart; }



void Mob::gotoNextStep() {
    // TODO

    /*

        int step=mob->getStep();
        if ( mob->isW() ){
            if ( mob->getDirection()==DIRECT::E ) { step++ ; }
            if ( mob->getDirection()==DIRECT::W ) { step-- ; }
        } else {
            if ( mob->getDirection()==DIRECT::S ) { step++; }
            if ( mob->getDirection()==DIRECT::N ) { step--; }
        }
        mob->setStep(step);

        // in range
        if ( mob->getStep()>=0 && mob->getStep()<=STEPS) return;
        // out range
        bool onStart=false;
        if ( mob->getStep()<0 ) { mob->setStep(0); onStart=true; } else { mob->setStep(STEPS); }
        int edge = b.edgeChessPosition( mob->getBridge(), onStart );
        mob->getExits() = b.getAllWaysFromEdge( edge );
        //nextDirection
        if ( mob->getExits().count(mob->getNextDirection())>0 && mob->getNextDirection()!=DIRECT::STOP ){ mob->setDirection( mob->getNextDirection()); mob->setNextDirection( DIRECT ::STOP );  }
        if ( mob->getExits().count(mob->getDirection())>0 ){
            moveMobNextBridge( mob , onStart );
        }

     */
}



void Mob::gotoNextBridge() {
    // TODO
    /*
    int actualBridgeNum = mob->getBridge();
    int edge = b.edgeChessPosition(actualBridgeNum, onStart);
    if (b.isExistsWayFromEdge(edge, mob->getDirection())) {
        int nextBridge = b.getWayFromEdge(edge, mob->getDirection());
        mob->setBridge(nextBridge);
        if (mob->getStep() == 0) { mob->setStep(STEPS); } else { mob->setStep(0); }
        mob->isW(b.isW(mob->getBridge()));
    }
     */
}






void Mob::setStep(int step) { Mob::step = step; }
int Mob::getStep() const { return step; }


