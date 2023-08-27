
#include <iostream>
#include "allTest.h"
#include "src/TickRunner.h"

int main() {

    bool allTest=!true;  // czy uruchamic wszystkie testy
    bool lastTest=true;  // czy uruchamia ostatni test (nad ktorym wlasnie pracuje) ?
    bool exitAfterTests=true; // czy po zakonczeniu testow zakonczyc aplikacje ?


    if ( allTest ) {
        // ** TEST ** Client/Server communication
        runMyTests();  // uruchamia w innym watki serwer ktory nasuchuje w petli
                       // i odpowiada tym samym,
                       // jesli otrzyma w parametrze "k" to konczy dzialanie

        // ** TEST ** tick
        TickRun();  // uruchamia runTickInThread()  w innym watku
        //           runTickInThread() uruchamia w petli Tick::tick(); co 500 ms
        sleep(5);       // usypia glowny watek na 5 sek, dzieki temu widac czy dzialaja inne watki

        return 0;
    }
    if ( lastTest ) {

    }

    if (exitAfterTests){return 0;}
    std::cout << "Hello, World!" << std::endl;
    //createServer();


    return 0;
}
