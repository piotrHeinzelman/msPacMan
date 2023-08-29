
#include <iostream>
#include "allTest.h"
#include "src/ConsoleDraw.h"


int main() {

    bool allTest=!true;  // czy uruchamic wszystkie testy
    bool lastTest=true;  // czy uruchamia ostatni test (nad ktorym wlasnie pracuje) ?
    bool exitAfterTests=true; // czy po zakonczeniu testow zakonczyc aplikacje ?


    if ( allTest ) runAllTests();
    if ( lastTest ) runLastTests();

    sleep(15);
    if (exitAfterTests){return 0;}
    std::cout << "Hello, World!" << std::endl;
    //createServer();


    return 0;
}
