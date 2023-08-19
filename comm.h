//
// Created by John on 8/20/2023.
//

#ifndef XXX_COMM_H
#define XXX_COMM_H


#include <string>

class comm {

private:
    std::string serverAdd;

public:
    int connect(  std::string const& serverAddr );
    void disconnect();

};


#endif //XXX_COMM_H
