//
// Created by Bill on 9/1/2023.
//

#include "Board.h"

void Board::addMob( Mob* mob ) {
    if (mobs.size() < 8 ){
    mobs.push_back( mob );
    }
}