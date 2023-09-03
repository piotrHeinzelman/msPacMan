//
// Created by Bill on 8/28/2023.
//

#ifndef MSPACMAN_MOB_H
#define MSPACMAN_MOB_H


#include <string>
#include "DIRECT.h"
#include "Board.h"
#include <set>

#define STEPS 6

class Board ;

class Mob {

private:
    int id;
    int step;
    bool goForwart; // ?
    int bridge;

    std::set<DIRECT> exits={};//= {DIRECT::N, DIRECT::S};

    DIRECT direction;
    DIRECT nextDirection;

    bool isW_;
    int points=0;
    int power=0;
    bool ghost;
    Board* board;



public:
    Mob();
    Mob(int id , std::string name , Board* board,  bool ghost=false );
    int getId();


// getters / setters

    bool isGoForwart() const;

    void setGoForwart(bool goForwart);

    int getBridge();
     void setBridge(int bridgeNum);

      int getStep();
     void setStep(int step );

    DIRECT getDirection();
      void setDirection(DIRECT direction);

    DIRECT getNextDirection();
      void setNextDirection(DIRECT direction);


    // *** trivial
    bool isW() const;
    void isW( bool isW );

    void addPoint( int points );
    void addPower( int power );
    int getPower();
    int getPoints();
    bool isGhost();
    std::set<DIRECT> &getExits();



    void insertMobAtBridge(Mob *mob, int bridge);

};


#endif //MSPACMAN_MOB_H
