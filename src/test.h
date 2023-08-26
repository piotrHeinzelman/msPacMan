//
// Created by John on 2023-08-26.
//

#ifndef MSPACMAN_TEST_H
#define MSPACMAN_TEST_H


#include <cstdio>

class test
{
public:
    bool flag;
    test() { flag=true; }
    void start_do(){ while(flag) std::puts("doing...");}
    void stop_do() { flag=0; }



};




#endif //MSPACMAN_TEST_H
