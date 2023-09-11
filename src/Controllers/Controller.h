//
// Created by Bill on 9/8/2023.
//

#ifndef MSPACMAN_CONTROLLER_H
#define MSPACMAN_CONTROLLER_H



// https://www.geeksforgeeks.org/signal-handling-in-cpp/
// https://downloads.ti.com/docs/esd/SPRUI04/the---interrupt-keyword-stdz0559860.html

#include <string>
#include "../Ways.h"
#include "../DIRECT.h"
#include "../Mob.h"
#include "../Bridge.h"

class Controller {

protected:
    int id=0;
    char avatar='?';
    std::string name;
    bool ghost;
    Mob* mob= nullptr;
    Bridge* bridge=nullptr;

    int step=0;
    DIRECT direction=DIRECT::STOP;     // <- DONT USE setDirection! (only +-)
    DIRECT nextDirection=DIRECT::STOP; // <- USE nextDirection !
    long long ghostIntel=0;

public:
    explicit Controller( const std::string &name , bool ghost, Bridge* bridge );

    virtual void IamOnEdge(); // <-- void getNexWayFrom( Ways w );
    virtual void checkTick(Controller *mob);

    Mob* getMob();



    DIRECT getDirection() const;
    DIRECT getNextDirection() const;
    void setDirection( DIRECT direction );
    void setNextDirection( DIRECT nextDirection );
    bool isGhost();
    int  getStep() const;
    void setStep(int step);

    Bridge *getBridge();
    void setBridge(Bridge *bridge);


    void gotoNextStep();
    void gotoNextBridge(  DIRECT dir, Ways w  );
    void checkNextDirection();
    COORD getAvatarPosition();
    char getAvatarCode();

    char* ControllerToShadowString();

    int getId() const;

    void setId(int id);
};


#endif //MSPACMAN_CONTROLLER_H
