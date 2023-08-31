//
// Created by Bill on 8/31/2023.
//

#include "Dot.h"

Dot::Dot(int parentBridge, const COORD &point, int value, int power) {
    this->parentBridge=parentBridge;
    this->point=point;
    this->value=value;
    this->power=power;
}
