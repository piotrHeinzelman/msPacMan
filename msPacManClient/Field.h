#ifndef FIELD_H
#define FIELD_H

#include <QMap>
#include <direction.h>
#include "Actor.h"


class Field {

public:
    Field();
    Field( int type );
    ~Field();
    void setPoint ( int type );
    void setNeighbour( Direction direction , Field neighbour );
    void grabPoint( Actor actor );
    Field getNeighbour( Direction direction );

private:
    int fieldType;     // 1 small dot
                       // 2 big   dot
                       // 3 no    dot
                       // 4 fruit
                       //
    //QMap<int, Field> neighbours;
    QMap<Direction, Field> neighbours;
    //Field* neighbours[ DIRECTION_LENGTH ]; //Direction size [4];
};

#endif // FIELD_H
