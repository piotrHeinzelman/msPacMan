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
    int positionOnBridge;
    DIRECT direction;
    DIRECT nextDirection;
    Board* parent;
    int points=0;
    int power=0;
    bool ghost;
    Board* board;

public:
    Mob();
    Mob(int id , std::string name , Board* board,  bool ghost=false );

    unsigned short getId();
    void setPositionOnBridge(int position );
    int  getPositionOnBridge();
    void step();
    void setDirection(DIRECT direction);
    void _atEdge();
    bool isAtEdge();
    void setParent( Board* parent );
    void addPoint( int points );
    void addPower( int power );

    int getPower();
    DIRECT getDirection();
    int getPoints();
    bool isGhost();


    void stepN( bool isW );
    void stepE( bool isW );
    void stepW( bool isW );
    void stepS( bool isW );

};


#endif //MSPACMAN_MOB_H
