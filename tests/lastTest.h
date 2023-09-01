//
// Created by Bill on 8/23/2023.
//

#ifndef MSPACMAN_ALLTEST_HA
#define MSPACMAN_ALLTEST_HA

#include "../src/Board.h"

void run_Last_Test(){
    Board b;
    Mob* Pac = new Mob( 4, "Pac", false );
         Pac->setField('J',19);
          b.addMob( Pac );
}

#endif //MSPACMAN_ALLTEST_H
