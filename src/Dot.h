//
// Created by Bill on 8/31/2023.
//

#ifndef MSPACMAN_DOT_H
#define MSPACMAN_DOT_H

#include "Board.h"


class Dot {

private:
    int parentBridge;
    COORD point;
    int value;
    int power;

public:
    Dot(int parentBridge, const COORD &point, int value=1, int power=0 );
    int getPower();
};


#endif //MSPACMAN_DOT_H
