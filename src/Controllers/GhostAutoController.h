//
// Created by Bill on 9/9/2023.
//

#ifndef MSPACMAN_GHOSTAUTOCONTROLLER_H
#define MSPACMAN_GHOSTAUTOCONTROLLER_H

#include "Controller.h"


class GhostAutoController : public Controller {

private:
public:
    GhostAutoController(  const std::string &name , bool ghost, Bridge* bridge ) ;

    void IamOnEdge() override; // <-- void getNexWayFrom( Ways w );
     void checkTick(Controller *mob) override;



};


#endif //MSPACMAN_GHOSTAUTOCONTROLLER_H
