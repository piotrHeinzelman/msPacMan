//
// Created by John on 9/4/2023.
//

#ifndef MSPACMAN_BRIDGE_H
#define MSPACMAN_BRIDGE_H


#include <utility>
#include "Ways.h"
#include "ConsoleDraw.h"

class Bridge {
private:
    int bridgeNum;
    std::pair<int,int> chessPosition;
    int startEdge;
    int endEdge;
    Ways startWays;
    Ways endWays;

public:
    explicit Bridge( int bridgeNum );

    int getStartEdge() ;
    int getEndEdge() ;
    COORD getCenterPoint() const;
    COORD getStartPoint() const;
    COORD getEndPoint() const;

    bool isW() const;

    COORD transformChessToScreen( COORD point ) const;

    const Ways &getStartWays() const;

    void setStartWays(const Ways &startWays);

    const Ways &getEndWays() const;

    void setEndWays(const Ways &endWays);

};


#endif //MSPACMAN_BRIDGE_H
