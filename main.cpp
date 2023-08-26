
#include <iostream>
#include "allTest.h"
#include "src/Tick.h"

int main() {

    bool allTest=false;
    bool lastTest=true;


    if ( allTest ) {
        // run test Client/Server communication
        runMyTests();
        return 0;
    }
    if ( lastTest ) {
        // run Tick
        Tick t;
        t.run();
        sleep(5);
    }


    std::cout << "Hello, World!" << std::endl;
    //createServer();


    return 0;
}
