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
  S>C  'BYE'   <
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
    std::string buf="";


public:
    explicit Server( Board* board );
    void command (std::string & buf );
          void Login( std::string & buf );
          void logOut( std::string & buf  );
          void Mobiles( std::string & buf );
          void Dots( std::string & buf  );
          void Goto( std::string & buf  );
          void getBridges( std::string & buf  );
          void createMobsFromString( std::string & buf  );



};


#endif //MSPACMAN_SERVER_H
