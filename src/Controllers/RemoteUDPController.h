//
// Created by Bill on 9/9/2023.
//

#ifndef MSPACMAN_REMOTEUDPCONTROLLER_H
#define MSPACMAN_REMOTEUDPCONTROLLER_H

#include "Controller.h"


class RemoteUDPController : public Controller {

private:
public:
    RemoteUDPController(  const std::string &name , bool ghost, Bridge* bridge );

    void IamOnEdge() override; // <-- void getNexWayFrom( Ways w );
    void checkTick(Controller *mob) override;



};


#endif //MSPACMAN_REMOTEUDPCONTROLLER_H
