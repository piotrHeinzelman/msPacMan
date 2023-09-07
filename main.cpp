
#include <iostream>
#include <future>
#include <thread>
#include "tests/allTest.h"
#include "src/ConsoleDraw.h"
#include "tests/CppTests.h"
#include "src/UDPServ.h"
#include "tests/SecondTest.h"



int main() {

    std::string serverIp;
    std::cout << "\n\n\n"
                 "                       PAC MAN\n\npodaj adres serwera, lub ENTER dla uruchomienia serwera i gry lokalnej.\n:";
    getline(std::cin, serverIp);
    if ( serverIp.length()==0 ) {
        Board* board = new Board();
               board->PlayLocal();
               sleep(1);
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
    return 0;

    sleep(5);


    if ( true ) {
        Board* board;
               board->PlayLocal();
               return 0;
    }













    // create server // TURN OFF< read key
    //HANDLE thread = CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(createClient), &b1, 1, NULL);


    bool cppTest=!true;  // uruchomic cppcheck
    bool secTest=!true;  // uruchomic secondtest
    bool allTest=!true;  // czy uruchamic wszystkie testy
    bool lastTest=!true;  // czy uruchamia ostatni test (nad ktorym wlasnie pracuje) ?
    bool exitAfterTests=!true; // czy po zakonczeniu testow zakonczyc aplikacje ?


    if ( cppTest ) { CppTests cppt; cppt.BridgesTest();  }
    if ( allTest ) runAllTests();
    if ( lastTest ) runLastTests();
    if ( secTest ) {
        SecondTest sc;
                   sc.runTest();
    }

    if (exitAfterTests){ return 0; }


    //std::cout << "Hello, World!" << std::endl;


    Board b1;
    b1.prepare();
    b1.drawBoard();
    b1.drawAllDots();
    b1.drawAllMob();

    b1.getPlayersMob()->setNextDirection( DIRECT::E );
    b1.getPlayersMob()->setDirection( DIRECT::E );





    // odrysowywanie do timer
    //
    // HANDLE thread1 = CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>( RefreshBoard ), &b1, 1, NULL);



    // LOCAL CONTROLLER
    Mob* player = b1.getPlayersMob();
    DIRECT activeDirection=DIRECT::STOP;
    DIRECT d;
    while(true){
        if (GetKeyState(VK_UP   ) < 0 ) { d=DIRECT::N; if (d != activeDirection ) { activeDirection=d; player->setNextDirection( d ); }}
        if (GetKeyState(VK_DOWN ) < 0 ) { d=DIRECT::S; if (d != activeDirection ) { activeDirection=d; player->setNextDirection( d ); }}
        if (GetKeyState(VK_LEFT ) < 0 ) { d=DIRECT::W; if (d != activeDirection ) { activeDirection=d; player->setNextDirection( d ); }}
        if (GetKeyState(VK_RIGHT) < 0 ) { d=DIRECT::E; if (d != activeDirection ) { activeDirection=d; player->setNextDirection( d ); }}
        //if (GetKeyState(VK_SPACE) < 0 ) { std::cout << "Bridge:" << player->getBridge()->getBridgeNum()<<", position:"<<player->getStep()<<"\n"; }
    }


    //return 0;
}
