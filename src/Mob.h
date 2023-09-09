//
// Created by Bill on 8/28/2023.
//

#ifndef MSPACMAN_MOB_H
#define MSPACMAN_MOB_H


#include <string>
#include "DIRECT.h"
#include "Board.h"
#include "Bridge.h"
#include "Controllers/Controller.h"
#include <set>

#define STEPS 6

class Board ;

class Mob {

private:
    int id;
    int lives;
    int step;

    Controller* controller;

    Bridge* bridge;

    std::set<DIRECT> exits={};//= {DIRECT::N, DIRECT::S};



    int points=0;
    int power=0;
    Board* board;



public:
    Mob();
    Mob(int id , Controller* controller , Board* board );
    void gotoNextStep();
    void gotoNextBridge(  DIRECT dir, Ways w  );

    // getters / setters

      Bridge * getBridge();
     void setBridge(Bridge* bridge);

    int  getStep() const;
    void setStep(int step);
    COORD getAvatarPosition();

    DIRECT getDirection();
      void setDirection(DIRECT direction);
      void setNextDirection(DIRECT direction);

    void addPoint( u_long points );
    void addPower( int power );
    int getPower();
    int getPoints();
    bool isGhost();
    std::set<DIRECT> &getExits();

    void insertMobAtBridge(Mob *mob, int bridge);

    void checkNextDirection();
    void grabEnergy();

    int getLives();
    void setLives(int lives);
    int gameOver();

    int getId() const;

};

#endif //MSPACMAN_MOB_H
