
#include <iostream>
#include "tests/lastTest.h"
#include "src/Board.h"


int main() {
    bool last_Test=true;  // czy uruchamia ostatni test (nad ktorym wlasnie pracuje) ?
    bool exitAfterTests=true; // czy po zakonczeniu testow zakonczyc aplikacje ?


    if ( last_Test ) run_Last_Test();



    if (exitAfterTests){ return 0; }

    Board board;



    return 0;
}
