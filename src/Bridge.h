//
// Created by John on 9/4/2023.
//

#ifndef MSPACMAN_BRIDGE_H
#define MSPACMAN_BRIDGE_H


#include <utility>

class Bridge {
private:
    int intPosition;
    std::pair<int,int> chessPosition;
    Bridge* startWays[4]={nullptr};
    Bridge* endWays[4]={nullptr};

public:
    Bridge( int intPosition );

};


#endif //MSPACMAN_BRIDGE_H
