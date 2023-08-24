//
// Created by Bill on 8/24/2023.
//

#ifndef MSPACMAN_SERVTEST_H
#define MSPACMAN_SERVTEST_H


#include <cassert>

class ServTest  {

public:
    void runAllTest(){
        printf ("ServTest::runAllTest();");
        assert( true );
        if ( true ) throw std::domain_error("test::exception");
    }
};


#endif //MSPACMAN_SERVTEST_H
