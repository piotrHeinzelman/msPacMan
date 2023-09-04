//
// Created by John on 9/4/2023.
//

#include "Bridge.h"

Bridge::Bridge( int bridgeNum ) {
    this->bridgeNum=bridgeNum;
    if ( bridgeNum%2==1 ){
        this->startEdge=bridgeNum-1;
          this->endEdge=bridgeNum+1;
    } else {
        this->startEdge=bridgeNum-10;
          this->endEdge=bridgeNum+10;
    }
}

int Bridge::getStartEdge() const { return startEdge; }
int Bridge::getEndEdge() const { return endEdge; }

const Ways &Bridge::getStartWays() const { return startWays; }
void Bridge::setStartWays(const Ways &startWays) { Bridge::startWays = startWays; }
const Ways &Bridge::getEndWays() const { return endWays; }
void Bridge::setEndWays(const Ways &endWays) { Bridge::endWays = endWays; }
