//
// Created by Bill on 8/28/2023.
//

#ifndef MSPACMAN_MOB_H
#define MSPACMAN_MOB_H


#include <string>
#include "DIRECT.h"
#include "Board.h"
#include "Bridge.h"
#include <set>

#define STEPS 6

class Board ;

class Mob {

private:
    int id;
    int step;
    bool goForwart; // ?
    Bridge* bridge;

    std::set<DIRECT> exits={};//= {DIRECT::N, DIRECT::S};

    DIRECT direction;
    DIRECT nextDirection;

    int points=0;
    int power=0;
    bool ghost;
    Board* board;



public:
    Mob();
    Mob(int id , std::string name , Board* board,  bool ghost=false );
    int getId();

    void gotoNextStep();

    bool isGoForwart() const;
    void setGoForwart(bool goForwart);
// getters / setters




      Bridge * getBridge();
     void setBridge(Bridge* bridge);

    int  getStep() const;
    void setStep(int step);

    DIRECT getDirection();
      void setDirection(DIRECT direction);
      void setNextDirection(DIRECT direction);

    void addPoint( int points );
    void addPower( int power );
    int getPower();
    int getPoints();
    bool isGhost();
    std::set<DIRECT> &getExits();



    void insertMobAtBridge(Mob *mob, int bridge);
    void gotoNextBridge();

};

#endif //MSPACMAN_MOB_H
