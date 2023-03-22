#ifndef ACTOR_H
#define ACTOR_H


class Actor
{
public:
    Actor();
    void addPoint( int point );
    void increasePower();
private:
    int points=0;
    int power=0;

};

#endif // ACTOR_H
