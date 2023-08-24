//
// Created by Bill on 8/23/2023.
//

#ifndef MSPACMAN_ALLTEST_H
#define MSPACMAN_ALLTEST_H



#include "tests/ServTest.h"

int runMyTests( int a ) {

    ServTest servTest;
    servTest.runAllTest();

    return a;
    }



#endif //MSPACMAN_ALLTEST_H
