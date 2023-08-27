//
// Created by John on 2023-08-27.
//

#ifndef MSPACMAN_BOARD_H
#define MSPACMAN_BOARD_H

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



*/

class Board {




};


#endif //MSPACMAN_BOARD_H
