//
// Created by Bill on 8/28/2023.
//

#ifndef MSPACMAN_MOB_H
#define MSPACMAN_MOB_H




#define STEPS 6

class Board ;

class Mob {

private:
    int id;
    int lives;

    int points=0;
    int power=0;


public:
    Mob();

    void addPoint( unsigned int points );
    void addPower( int power );
    int getPower();
    int getPoints();


    void grabEnergy();

    int getLives();
    void setLives(int lives);
    int gameOver();


};

#endif //MSPACMAN_MOB_H
