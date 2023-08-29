//
// Created by John on 2023-08-27.
//

#ifndef MSPACMAN_BOARD_H
#define MSPACMAN_BOARD_H


#define BOARD_WIDTH 19
#define BOARD_HEIGHT 23

#define CELL_WIDTH 3 //6
#define CELL_HEIGHT 2 // 2

#define BH BOARD_HEIGHT*CELL_HEIGHT
#define BW BOARD_WIDTH*CELL_WIDTH

#define popW 0
#define popH 0


#include <vector>
#include <iostream>
#include "Mob.h"
#include "DIRECT.h"
#include "ConsoleDraw.h"



/* glowna klasa gry
   przechowuje
    - Mob - postacie grajace na planszy (zarowno Ghost jak i Pac)
    - Masters - włascicieli Mobów, Masters mogą być zdalni przez sieć, lub lokalni ( ludzie lub automaty )
              - Masters nadaja swoim Mob-om proponowany kierunek skretu w nastepnym wezle (Node).

              - Mob - zawsze podrozuje po moście (Bridge) na koncu mostu jest Node gdzie schodza sie Bridge.
                      tylko na koncach Bridge jest mozliza zmiana kierunku z akrualnej na proponowaną o ile taki kierunek wystepuje w węźle,
                      jeśli nie mozna skręcic Mob porusza się dalej w kierunku poprzednim o ile jest taka możliwość
                      jesli nie można iść, Mob zatrzymuje się i czeka.

     Board cyklicznie uruchamia metodę MobMove - która przesuwa Moby , na Bridge, wykrywa kolizje, zmienia kierunki ruchu z proponowanego na aktualny.
     usuwa kropki Dot z Bridge i przyznaje punkty o ile Mob jest klasy Pac,


    Node/Bridge - graf nieskierowany

    węzły Node - podobne do pól szachownicy identyfikowane dwoma pair<ushort,ushort>
        górny lewy węzeł <0,0> , górny prawy <0,5> dolny lewy <8,0>
        wszystkie Bridge "idą" w kierunku w prawo lub w dół
            (tzn, np początek mostu <0,0> koniec <0,1> lub poczatek <0,0> koniec <1,0>)
            po moście mozna iść w dowolne strony - graf nieskierowany

     Bridge - most / krawędz ma kilka kroków, na środkowym i końcowym znajdują się Dot które dają punkty, i które trzeba "zjeść" zyskując punkty i aby przejść na nastepna planszę

    -------------------------
    x  .  C->.   .   .   .  X
    -------------------------
    x koniec mostu
    . krok na moście
    C mob
    (nie zaznaczono Dot)

    Board - plansza:

      0,0     0,1      0,2
        =-----= =------=
       Y       Y
       |       |
       |       |
      1,0     1,1


     klasa Tick cyklicznie uruchamia MobMove na obiekcie Board.

     zadlni uzytkownicy - klienci mogą:
        dołaczyć do gry login() - podając 3-literowe imie i rodzaj Mob-a ( Ghost | mrPac / msPac )
        wyjść z gry logout()    - podajac swoj identyfikator
        pobrać szkic planszy, i rozkład mostów by narysować tło
        pobrać połozenie Mob na mostach i zaktualizować wygląd planszy zmieniając tylko obraz mostów na których stoi Mob.


        NODES:

        0   2   4   6   8   10  12  14  16  18

       20  22  24  26  28  30   32  34  36  38

       40 [41] 42 [most] 44

       60
      [70] - most
       80

       most nieparzysty - poziomy
       n+2(E) = n`  if exists n+1 (czyli jeśli istnieje most o numerze n+1 to można przejść w kierunku "E" z n do n+2
       n-2(W) = n`  if exists n-1

       most pionowy
       n+20(S) = n` //if (n+10) exists
       n-20(N) = n` //if (n-10) exists


       a    a+2  ruch w prawo (E)
       n -> n
        [a+1] - Bridge

        a-2   a  ruch w lewo (W)
         n <- n
  Bridge  [a-1]

           ruch w dół (S)

         Node  a
               |
           most (a+10)
               \/
         Node a+20



 ****************************************



  do przechowywania "mostów" uzyje starej dobrej tablicy B[255]  B[x]=" "- brak mostu, B[x]!=" " most - szybko i skutecznie bez wikłania się w nowoczesne struktury danych, drzewa, mapy, czy przeglądanie iteratorami vector<?>

char Bridges[255]=
    //Bridge E
//         01234567890123456789
/!00-19!/ " x x x x  xx xxx xx "\
/!20-39!/ "xx xxx xxxxx xxxxx  "\
/!40-59!/ " xxxx  xx  x  xx xx "\
/!60-79!/ "x   x  x x    x x   "\
/!80-99!/ "  x x         x x   "\
/100-119/ " xxxxx x     xxxxx !"\
/120-139/ "  x x         x x   "
/140-159/ "  x x  x x x  x x   "
/160-179/ " xxxxx x  xx xxx xx "
/180-199/ "xx  xx xxx xxxx xx  "
/200-219/ " xxxx xx  xx   x xx "
/220-239/ "xx x x x x x x x xx "
//         01234567890123456789

//    char Bridges[255]=" x x x x  xx xxx xx "-"xx xxx xxxxx xxxxx  "-" xxxx  xx  x  xx xx "-"x   x  x x    x x   "-"  x x         x x   "-" xxxxx x     xxxxx !"-"  x x         x x   "-"  x x  x x x  x x   "-" xxxxx x  xx xxx xx "-"xx  xx xxx xxxx xx  "-" xxxx xx  xx   x xx "-"xx x x x x x x x xx ";

 https://cpp0x.pl/dokumentacja/WinAPI/Konsola/1038
*/
class Mob;
class Board {

private:
    Mob* mobiles[8]={};
    int activeBridges [8]={0};
    ConsoleDraw cdraw;


public:
    std::string Bridges;

    Board();
    void BoardTick();

    void prepare();
    void setMobAt( int  i , int bridgeNum );
    void moveMobTo ( int i, DIRECT STOP, int bridgeNum );


    void deactivateBridge( int bridgeNum );
    void activateBridge( int bridgeNum  );

    void drawBridge( int bridgeNum );
    void drawBridgeW( int bridgeNum );
    void drawBridgeH( int bridgeNum );

    DIRECT atEdge( int id , DIRECT direction , DIRECT nextDirection );

    void drawBoard();


};


#endif //MSPACMAN_BOARD_H
