
#include <iostream>
#include "comm.h"

#include "tests/myTests.h"

int main() {
    if ( true ){ myTests T; T.run(); return 0; }


    std::cout << "Hello, World!" << std::endl;

    std::string serverAddr = "127.0.0.1";
    int serverPort = 8080;


    comm cm;
    cm.connect( serverAddr , serverPort );
    cm.disconnect();

    return 0;
}
