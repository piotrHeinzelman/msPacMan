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

class Controller {

private:

    std::string name;
    bool ghost;

    DIRECT direction=DIRECT::STOP;     // <- DONT USE setDirection! (only +-)
    DIRECT nextDirection=DIRECT::STOP; // <- USE nextDirection !

public:
    explicit Controller( const std::string &name , bool ghost );

    void getNexWayFrom( Ways w );
    DIRECT getDirection() const;
    void setDirection(DIRECT direction);

    bool isGhost();

    DIRECT getNextDirection() const;
    void setNextDirection(DIRECT nextDirection);

};


#endif //MSPACMAN_CONTROLLER_H
