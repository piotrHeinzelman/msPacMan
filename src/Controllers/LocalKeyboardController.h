//
// Created by Bill on 9/9/2023.
//

#ifndef MSPACMAN_LOCALKEYBOARDCONTROLLER_H
#define MSPACMAN_LOCALKEYBOARDCONTROLLER_H

#include "Controller.h"


class LocalKeyboardController : public Controller {

private:
public:
    LocalKeyboardController(  const std::string &name , bool ghost, Bridge* bridge );

    void IamOnEdge() override; // <-- void getNexWayFrom( Ways w );
    void checkTick(Controller *mob) override;



};


#endif //MSPACMAN_LOCALKEYBOARDCONTROLLER_H
