//
// Created by Bill on 9/9/2023.
//
#include "RemoteUDPController.h"

RemoteUDPController::RemoteUDPController(const std::string &name, bool ghost, Bridge *bridge)
    : Controller(name, ghost,  bridge) { }

void RemoteUDPController::IamOnEdge() {
    //NOP
}

void RemoteUDPController::checkTick(Controller *mob) {
/*
    ConsoleDraw cdraw;
    cdraw.cls();
    std::cout << "try connect:" << serverIp;
    UDPClient* client = new UDPClient( serverIp );
    char buf[255];
    DIRECT d;

    while(true){
        if (GetKeyState(VK_UP   ) < 0 ) { buf[0]='G'; buf[1]='N'; buf[2]=0; client->setBuff(buf); client->send();  } // GoNorth
        if (GetKeyState(VK_DOWN ) < 0 ) { buf[0]='G'; buf[1]='S'; buf[2]=0; client->setBuff(buf); client->send();  } // GoNorth
        if (GetKeyState(VK_LEFT ) < 0 ) { buf[0]='G'; buf[1]='W'; buf[2]=0; client->setBuff(buf); client->send();  } // GoNorth
        if (GetKeyState(VK_RIGHT) < 0 ) { buf[0]='G'; buf[1]='E'; buf[2]=0; client->setBuff(buf); client->send();  } // GoNorth
        std::cout << client->getBuff();
    }
    */
}

    //NOP
}