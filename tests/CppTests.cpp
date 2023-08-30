//
// Created by Bill on 8/30/2023.
//

#include <iostream>
#include <cassert>
#include "CppTests.h"


void CppTests::BridgesTest(){

    Bridges b;

    assert(2+2==4);
    assert( false == b.isExsits(0) );
    assert( true == b.isExsits(1) );
    assert( false == b.isExsits(2) );
    assert( true == b.isExsits(10) );

    assert( true == b.isW(1) );
    assert( false == b.isW(10) );

    bool fromStart=true;
    assert( 0 == b.edgePosition( 1 , fromStart) );
    assert( 2 == b.edgePosition( 1 , !fromStart) );

    assert( 20 == b.edgePosition( 30 , fromStart) );
    assert( 40 == b.edgePosition( 30 , !fromStart) );





};