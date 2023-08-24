//
// Created by Bill on 8/23/2023.
//

#ifndef MSPACMAN_SUM_INTEGERS_H
#define MSPACMAN_SUM_INTEGERS_H


#include "sum_integers.h"
#include <vector>

int sum_integers(const std::vector<int> integers) {
    auto sum = 0;
    for (auto i : integers) {
        sum += i;
    }
    return sum;
}


#endif //MSPACMAN_SUM_INTEGERS_H
