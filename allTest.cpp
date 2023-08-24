//
// Created by Bill on 8/23/2023.
//

#include <cppunit/TestResult.h>
#include <cppunit/TestCase.h>
#include <cppunit/TestAssert.h>

#include "allTest.h"

class allTest : public CppUnit::TestCase {

public:
    void runTest() {
        CPPUNIT_ASSERT_EQUAL( true, true );
    };
};