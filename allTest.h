//
// Created by Bill on 8/23/2023.
//

#ifndef MSPACMAN_ALLTEST_H
#define MSPACMAN_ALLTEST_H



#include "tests/ServTest.h"

void runMyTests() {
    printf ("[ TEST ] :: runAllTest();\n");

    printf ("[ TEST ] :: ServTest::runAllTest();\n");
    ServTest servTest;
    servTest.runAllTest();

    }



#endif //MSPACMAN_ALLTEST_H
