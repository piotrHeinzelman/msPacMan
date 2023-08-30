//
// Created by Bill on 8/30/2023.
//

#include <iostream>
#include <cassert>
#include "CppTests.h"


void CppTests::BridgesTest(){

    std::cout << "before tests\n";

    Bridges b;

    std::cout << (DIRECT::N)/2 << "#4\n";

    assert(2+2==4);
    assert( false == b.isExsits(0) );
    std::cout << "#1\n";
    assert( true == b.isExsits(1) );
    assert( false == b.isExsits(2) );
    assert( true == b.isExsits(10) );
    std::cout << "#2\n";
    assert( true == b.isW(1) );
    assert( false == b.isW(10) );
    std::cout << "#3\n";
    assert( 0 == b.edgePosition( 1 , true) );
    std::cout << "#4\n";
    assert( 2 == b.edgePosition( 1 , false ) );
    std::cout << "#5\n";
    assert( 20 == b.edgePosition( 30 , true) );
    assert( 40 == b.edgePosition( 30 , false) );
    std::cout << "#6\n";

    std::cout << "after tests\n";


};