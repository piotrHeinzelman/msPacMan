
#include <iostream>
#include <future>
#include <thread>
#include <unistd.h>
#include "src/ConsoleDraw.h"
#include "src/UDPServ.h"
#include "src/Board.h"
#include "src/UDPClient.h"


int main() {

    std::string serverIp;
    std::cout << "\n\n\n"
                 "                       PAC MAN\n\npodaj adres serwera, lub ENTER dla uruchomienia serwera i gry lokalnej (NumKey).\n:";
    getline(std::cin, serverIp);
    if ( serverIp.length()==0 ) {
        Board* board = new Board();
               board->PlayLocal();

               while(true){

               }

        delete board;
        return 0;
    } else {
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

    }

}
