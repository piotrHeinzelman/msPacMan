#include "Field.h"

#include <stdio.h>
#include <stdlib.h>
#include "Actor.h"

Field::Field(){
    fieldType = 1;
};

Field::Field( int type ){
    this->setPoint( type );
};

void Field::setNeighbour( Direction direction , Field neighbour ){
    neighbours.insert( direction , neighbour );
};

void Field::setPoint( int type ){
    fieldType=type;
};

void Field::grabPoint( Actor actor ){
    if (fieldType==1) {
        actor.addPoint( 1 );
    }
    if (fieldType==2) {
        actor.increasePower();
    }
};

Field Field::getNeighbour( Direction direction ){
    neighbours.find( direction );
}

