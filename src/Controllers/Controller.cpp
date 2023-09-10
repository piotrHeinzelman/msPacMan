//
// Created by Bill on 9/8/2023.
//

#include <iostream>
#include "Controller.h"



Controller::Controller( const std::string &name , bool ghost, Bridge* bridge ) {
    Controller::name = name;
    Controller::ghost = ghost;
    this->avatar = ghost ? 'G' : 'P';
    Controller::bridge = bridge;
    mob = new Mob();
}


bool Controller::isGhost() { return ghost; }
DIRECT Controller::getDirection() const { return direction; }
DIRECT Controller::getNextDirection() const  { return nextDirection; }

void Controller::setDirection(DIRECT direction) { this->direction = direction; }
void Controller::setNextDirection( DIRECT nextDirection ) {
    this->nextDirection=nextDirection;
    if ( this->direction==DIRECT::STOP ) this->direction=nextDirection;
    if ( getBridge()->isW()){
        if (this->nextDirection==DIRECT::E || this->nextDirection==DIRECT::W  ) { this->direction=nextDirection;}
    } else {
        if (this->nextDirection==DIRECT::N || this->nextDirection==DIRECT::S  ) { this->direction=nextDirection;}
    }
}

void Controller::IamOnEdge() {
    //std::cout << "where should I go now?";
}


Mob *Controller::getMob() { return mob; }

int Controller::getStep() const { return step; }
void Controller::setStep( int step ) {
    if ( step>STEPS ) {step=STEPS;}
    if ( step<0 )     {step=0;}
    this->step = step;
}



Bridge *Controller::getBridge()  { return bridge; }
void Controller::setBridge(Bridge *bridge) { this->bridge = bridge; }



void Controller::gotoNextStep() {
    //if (id==4) { std::cout<<"Step:"<<getStep()<<", Bridge"<<getBridge()->getCenterPoint().X<<"\n"; }
    if (  step==0 || step==STEPS ) {
        IamOnEdge();
        checkNextDirection();
        Bridge* in = bridge;
        if ( step==0 ) {   //na poczatku
            gotoNextBridge(  direction , bridge->getStartWays() );
            // jeśli była zmiana
            if ( bridge!=in ) return;
        }
        else                {   gotoNextBridge(  direction , bridge->getEndWays()   );
            if ( bridge!=in ) return;
        }
    }

    if ( bridge->isW() ) {
        if ( direction==DIRECT::E ) { setStep(1+getStep()) ; }
        if ( direction==DIRECT::W ) { setStep(getStep()-1) ; }
    } else {
        if ( direction==DIRECT::N ) { setStep(getStep()-1) ; }
        if ( direction==DIRECT::S ) { setStep(1+getStep()) ; }
    }
}



void Controller::gotoNextBridge(  DIRECT dir , Ways w ) {
    switch( dir ){
        case DIRECT::N : if ( w.n!=nullptr ) { bridge=(Bridge*)w.n ; setStep( STEPS ); };  break;
        case DIRECT::W : if ( w.w!=nullptr ) { bridge=(Bridge*)w.w ; setStep( STEPS ); }; break;
        case DIRECT::S : if ( w.s!=nullptr ) { bridge=(Bridge*)w.s ; setStep( 0 ); };  break;
        case DIRECT::E : if ( w.e!=nullptr ) { bridge=(Bridge*)w.e ; setStep( 0 ); };  break;
        default: return;
    }
}



void Controller::checkNextDirection() {
    if ( nextDirection != DIRECT::STOP ){
        Ways w = (step==0) ? bridge->getStartWays() : bridge->getEndWays();
        if (getBridge()->isW()){
            if ( w.n!=nullptr && nextDirection==DIRECT::N ) direction=DIRECT::N ;
            if ( w.s!=nullptr && nextDirection==DIRECT::S ) direction=DIRECT::S ;
        } else {
            if ( w.e!=nullptr && nextDirection==DIRECT::E ) direction=DIRECT::E ;
            if ( w.w!=nullptr && nextDirection==DIRECT::W ) direction=DIRECT::W ;
        }
    }
}



COORD Controller::getAvatarPosition() {
    COORD startPoint = bridge->getStartPoint();
    int mobX = startPoint.X;
    int mobY = startPoint.Y;
// correction  point
    if (bridge->isW()) {
        mobX += step;
    } else {
        if (step > 1) mobY++;
        if (step > 4) mobY++;
    }
    return COORD {static_cast<SHORT>(mobX),static_cast<SHORT>(mobY) };
}

char Controller::getAvatarCode() {
    return avatar;
}

void Controller::checkTick( Controller* mob ) {
 /*   if ( step%STEPS==0) IamOnEdge();

    //void Board::mobCheckController( Mob* mob ) {
    if ( !mob->isGhost() ){
        if (GetAsyncKeyState(VK_UP) < 0) { mob->setNextDirection( DIRECT::N ); }
        if (GetAsyncKeyState(VK_DOWN) < 0) { mob->setNextDirection(  DIRECT::S ) ; }
        if (GetAsyncKeyState(VK_RIGHT) < 0) { mob->setNextDirection(  DIRECT::E ) ; }
        if (GetAsyncKeyState(VK_LEFT) < 0) { mob->setNextDirection(  DIRECT::W ) ; }
    }
    else {
        ghostIntel++;
        if (ghostIntel%10==3) mob->setDirection( DIRECT::N );
        if (ghostIntel%10==7) mob->setDirection( DIRECT::S );
        if (ghostIntel%11==4) mob->setDirection( DIRECT::W );
        if (ghostIntel%15==2) mob->setDirection( DIRECT::E );
    }*/
}

