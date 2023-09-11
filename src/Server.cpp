//
// Created by Bill on 9/10/2023.
//

#include "Server.h"

Server::Server(Board *board) {
    this->board = board;

}

void Server::command( std::string & buf ) {

    switch (buf[0]){
        case 'L': return Login( buf ); break;
        case 'O': return logOut( buf ); break;
        case 'M': return Mobiles( buf ); break;
        case 'C': return createMobsFromString( buf ); break;
        case 'D': return Dots( buf ); break;
        case 'G': return Goto( buf ); break;
        case 'B': return getBridges( buf ); break;
        default: break;
    }
}

// login
void Server::Login( std::string & buf ) {
    bool  isGhost=(buf[1]=='G');

    Controller* NewMob = new Controller("One", isGhost , board->getBridgeFrom( 2 ) );
    int i = board->addMob( NewMob );
    if ( i==-1 ) { throw std::runtime_error("MAX PLAYERS = 8"); }

    // reply
    buf[0]=(char)i;
    buf[1]=0;
}

// logout
void Server::logOut( std::string & buf) {
    int i = buf[1];
    board->removeMobFrom( i );
      // std::cout << "\n\ni:" << (int)i << "\n\n";
    buf[0]='B';
    buf[1]='Y';
    buf[2]='E';
    buf[3]=0;
}
void Server::Mobiles( std::string & buf ) {
    return board->getAllMobileAsString( buf );
}

// use in client ad test
void Server::createMobsFromString( std::string & buf  ){
    return board->createMobFromString( buf );
}

void Server::Dots( std::string & buf ) {
    board->getDotsAsString( buf );
}
void Server::Goto( std::string & buf ) { return ; }
void Server::getBridges( std::string & buf ) { return ; }
