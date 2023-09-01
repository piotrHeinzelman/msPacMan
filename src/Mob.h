//
// Created by Bill on 8/28/2023.
//

#ifndef MSPACMAN_MOB_H
#define MSPACMAN_MOB_H


#include <string>
#include "DIRECT.h"

#define STEPS 6

class Mob {
private:
    std::string name;
    int id;
    int step;
    int field;

    DIRECT direction;
    DIRECT nextDirection;

    int points=0;
    int power=0;

    bool ghost;

public:
    Mob();
    Mob(int id, std::string name,  bool ghost=false );

    // getters / setters
    int getStep() const;
    void setStep(int step);
    int getField() const;
    void setField(int field);
    DIRECT getDirection() const;
    void setDirection(DIRECT direction);


};


#endif //MSPACMAN_MOB_H
/*
      unsigned short getId();
    void setPositionOnBridge(int position );
    int  getPositionOnBridge();
    void nextStep();
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
    void checkNextDirection();


 */