//
// Created by Bill on 8/28/2023.
//

#ifndef MSPACMAN_MOB_H
#define MSPACMAN_MOB_H


#include <string>
#include "DIRECT.h"
#include "Board.h"


#define STEPS 6

class Board ;

class Mob {

private:
    int id;
    int step;
    int bridge;

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
// getters / setters



    int getBridge();
    void setBridge(int bridgeNum);

    void setStep(int step );
    int getStep();


    void setDirection(DIRECT direction);
    void setNextDirection(DIRECT direction);
    DIRECT getDirection();
    DIRECT getNextDirection();

    void nextStep();







    //
    void addPoint( int points );
    void addPower( int power );
    int getPower();
    int getPoints();
    bool isGhost();


    void stepN( bool isW );
    void stepE( bool isW );
    void stepW( bool isW );
    void stepS( bool isW );

    void insertMobAtBridge(Mob *mob, int bridge);
};


#endif //MSPACMAN_MOB_H
