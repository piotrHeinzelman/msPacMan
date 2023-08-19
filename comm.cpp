//
// Created by John on 8/20/2023.
//

#include <iostream>
#include "comm.h"

int comm::connect( std::string const& _serverAddr ){
    serverAdd = _serverAddr.c_str();
    return 1;
}

void comm::disconnect() {
    std::cout << "disconnect from: " << serverAdd;
}