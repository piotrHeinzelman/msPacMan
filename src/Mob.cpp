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
    if (id==4) { std::cout<<step; }
    int delta=0;
    if ( getBridge()->isW() ) {
        if ( getDirection()==DIRECT::E ) { delta++ ; }
        if ( getDirection()==DIRECT::W ) { delta-- ; }
    } else {
        if ( getDirection()==DIRECT::N ) { delta-- ; }
        if ( getDirection()==DIRECT::S ) { delta++ ; }
    }
    step+=delta;
    if ( step==0 || step==STEPS ) { // koniec planszy
        // zmiana kierunku ?
        Ways w = (step==0) ? getBridge()->getStartWays() : getBridge()->getEndWays();
        switch (nextDirection){ // zmiana kierunku ruchu na sugerowany następny kierunek i zmiana bridge na następny
                    case DIRECT::N: if (w.n!=nullptr ) { direction=nextDirection; nextDirection=DIRECT::STOP;} break;
                    case DIRECT::W: if (w.w!=nullptr ) { direction=nextDirection; nextDirection=DIRECT::STOP;} break;
                    case DIRECT::S: if (w.s!=nullptr ) { direction=nextDirection; nextDirection=DIRECT::STOP;} break;
                    case DIRECT::E: if (w.e!=nullptr ) { direction=nextDirection; nextDirection=DIRECT::STOP;} break;
        }
        switch (direction){ // zmiana bridge na następny
            case DIRECT::N: if (w.n!=nullptr ) { setBridge(w.n);} break;
            case DIRECT::W: if (w.w!=nullptr ) { setBridge(w.w);} break;
            case DIRECT::S: if (w.s!=nullptr ) { setBridge(w.s);} break;
            case DIRECT::E: if (w.e!=nullptr ) { setBridge(w.e);} break;
        }
    }
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


