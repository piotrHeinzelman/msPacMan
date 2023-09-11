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

int Dot::getPower(){
    return power;
};

int Dot::getValue(){
    return value;
};

int Dot::getParent(){
    return parentBridge;
}

std::string Dot::toString() {
    std::string s="      ";
    s[0]=(char) parentBridge;
    s[1]=(char) point.X;
    s[2]=(char) point.Y;
    s[3]=(char) value;
    s[4]=(char) power;
    return s;
};