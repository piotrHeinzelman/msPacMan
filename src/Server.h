//
// Created by Bill on 9/10/2023.
//

#ifndef MSPACMAN_SERVER_H
#define MSPACMAN_SERVER_H


#include "Board.h"

/*
 -------- login ------- Ghost / Pac
  C>S  'L' + 'G'|'P'    >
  S>C   int Id <
 -------- logut --------
  C>S  'O'+id  >
  S>C   'OK'   <
 -------- get mobiles / shadow ----
  C>S  'M'     >
  S>C  mobiles < mobiles: type, bridge, position, power ...
  ------- get dots  --------------
  C>S  'D'     >
  S>C  dots    <  dots: point,power
  ------- get bridges ------------
  C>S  'B'     >
  S>C  bridges < bridge : int position,
  --------- move my avatar ------------------
  C>S  'G'+Id+Direction >
  S<C  char Bridge, char position      <
  -------------------------------------------
 */

class Server {

private:
    Board* board;
    char buffIn[BUFFSIZE];
    char buffOut[BUFFSIZE];


public:
    explicit Server( Board* board );
    char* command ( char* buf );
          char* Login( char* buf );
          char* logOut( char* buf  );
          char* Mobiles( char* buf );
          char* Dots( char* buf  );
          char* Goto( char* buf  );
          char* getBridges( char* buf  );



};


#endif //MSPACMAN_SERVER_H
