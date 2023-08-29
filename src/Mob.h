//
// Created by Bill on 8/28/2023.
//

#ifndef MSPACMAN_MOB_H
#define MSPACMAN_MOB_H


#include <string>
#include "DIRECT.h"
#include "Board.h"


#define STEPS 8

class Board ;

class Mob {

private:
    int id;
    int positionOnBridge;
    DIRECT direction;
    DIRECT nextDirection;
    Board* parent;


public:
    Mob();
    Mob(int id , std::string name );

    unsigned short getId();
    void setPosition( int position );
    int getPosition();
    void step();
    void setDirection(DIRECT direction);
    void _atEdge();
    bool isAtEdge();
    void setParent( Board* parent );

};


#endif //MSPACMAN_MOB_H
