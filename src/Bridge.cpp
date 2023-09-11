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

int Bridge::getStartEdge()  { return startEdge; }
int Bridge::getEndEdge()  { return endEdge; }





bool Bridge::isW() const {
    return (bridgeNum%2==1) ;
}

COORD Bridge::transformChessToScreen(COORD point) const{
    point.X=1+(point.X*3);
    return point;
}


COORD Bridge::getCenterPoint() const {
    COORD point;
    if ( this->isW()) {
        point.X=bridgeNum%20;  point.Y=(bridgeNum-point.X)/10;
    } else {
        point.X=(bridgeNum-10)%20;  point.Y=1+2*((bridgeNum-10)/20);
    }
    return transformChessToScreen(point);
}

COORD Bridge::getStartPoint() const {
    COORD point = getCenterPoint();
    if ( this->isW()) {
        point.X=bridgeNum%20;  point.Y=(bridgeNum-point.X)/10;
        point.X--;
    } else {
        point.X=(bridgeNum-10)%20;  point.Y=1+2*((bridgeNum-10)/20);
        point.Y--;
    }
    return transformChessToScreen(point);
}

COORD Bridge::getEndPoint() const {
    COORD point = getCenterPoint();
    if ( this->isW()) {
        point.X=bridgeNum%20;  point.Y=(bridgeNum-point.X)/10;
        point.X++;
    } else {
        point.X=(bridgeNum-10)%20;  point.Y=1+2*((bridgeNum-10)/20);
        point.Y++;
    }
    return transformChessToScreen(point);
}

const Ways &Bridge::getStartWays() const { return startWays; }
void Bridge::setStartWays(const Ways &startWays) { this->startWays = startWays; }
const Ways &Bridge::getEndWays() const { return endWays; }
void Bridge::setEndWays(const Ways &endWays) { this->endWays = endWays; }
int Bridge::getBridgeNum() const { return this->bridgeNum; }








