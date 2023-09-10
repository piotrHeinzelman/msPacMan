//
// Created by Bill on 9/10/2023.
//

#include "Server.h"

Server::Server(Board *board) {
    this->board = board;

}

char* Server::command( char* buf ) {
    switch (buf[0]){
        case 'L': return Login( buf ); break;
        case 'O': return logOut( buf ); break;
        case 'M': return Mobiles( buf ); break;
        case 'D': return Dots( buf ); break;
        case 'G': return Goto( buf ); break;
        case 'B': return getBridges( buf ); break;
        default: break;
    }
    return nullptr;
}

// login
char* Server::Login( char *buf ) {
    bool  isGhost=(buf[1]=='G');

    Controller* NewMob = new Controller("One", isGhost , board->getBridgeFrom( 2 ) );
    int i = board->addMob( NewMob );
    if ( i==-1 ) { throw std::runtime_error("MAX PLAYERS = 8"); }

    // reply
    buf[0]=(char)i;
    buf[1]=0;
    return buf;
}

// logout
char* Server::logOut( char *buf ) {
    int i = buf[1];
    board->removeMobFrom( i );
      // std::cout << "\n\ni:" << (int)i << "\n\n";
    buf[0]='B';
    buf[1]='Y';
    buf[2]='E';
    buf[3]=0;
    return buf;
}
char* Server::Mobiles( char *buf ) { return nullptr; }
char* Server::Dots( char *buf ) { return nullptr; }
char* Server::Goto( char *buf ) { return nullptr; }
char* Server::getBridges( char *buf ) { return nullptr; }
