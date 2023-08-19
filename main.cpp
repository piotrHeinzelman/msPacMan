#include <iostream>
#include "comm.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::string serverAddr = "127.0.0.1";

    comm cm;
    cm.connect( serverAddr );
    cm.disconnect();

    return 0;
}
