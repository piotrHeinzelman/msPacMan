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

class Controller {

private:

    std::string name;
    bool ghost;
    Mob* parent = nullptr;

    DIRECT direction=DIRECT::STOP;     // <- DONT USE setDirection! (only +-)
    DIRECT nextDirection=DIRECT::STOP; // <- USE nextDirection !

public:
    explicit Controller( const std::string &name , bool ghost );

    virtual void IamOnEdge(); // <-- void getNexWayFrom( Ways w );

    void setDirection( DIRECT direction );
    void setNextDirection( DIRECT nextDirection );

    DIRECT getDirection() const;
    DIRECT getNextDirection() const;

    bool isGhost();
    void setParent( Mob* mob );


};


#endif //MSPACMAN_CONTROLLER_H
