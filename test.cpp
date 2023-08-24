


#include "sum_integers.h"
#include <iostream>

#include <vector>

int unit() {
    std::cout << "unit();";
}

int main() {

    std::cout << "test.cpp->main();";

    auto integers = {1, 2, 3, 4, 5};

    if (sum_integers(integers) == 15) {

        return 0;

    } else {

        return 1;

    }
}