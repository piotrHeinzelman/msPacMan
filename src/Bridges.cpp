//
// Created by Bill on 8/30/2023.
//

#include <iostream>
#include "Bridges.h"


/*  1   1         1         2         2         2
 *  7   8         9         0         1         2
    ░▒▓│┤╡╢╖╕╣║╗╝╜╛┐└┴┬├─┼╞╟╚╔╩╦╠═╬╧╨╤╥╙╘╒╓╫╪┘┌█▄▌▐▀
    678901234567890123456789012345678901234567890123
*/

Bridges::Bridges(){
    bridgesData = (char*)" x x x x  xx xxx xx xx xxx xxxxx xxxxx   xxxx  xx  x  xx xx x   x  x x x  x x     x x         x x    xxxxx       xxxxx !  x x         x x     x x  x x x  x x    xxxxx x  xx xxx xx xx  xx xxx xxxx xx   xxxx xx  xx   x xx xx x x xxx x x x x  ";
}


int Bridges::checkI(int bridgeNum ){
    if (bridgeNum < 0)   return 0;
    if (bridgeNum > 238) return 246;
    return bridgeNum;
}


bool Bridges::isExsits( int bridgeNum ){ //TESTED
    bridgeNum = checkI( bridgeNum );
    return bridgesData[ bridgeNum ]!=' ';
}


bool Bridges::isW(int bridgeNum){ // TESTED
    return (bridgeNum & 0x01)==1;
}


int Bridges::edgePosition( int bridgeNum, bool fromStart ){  // TESTED
    bool isW_ = isW( bridgeNum );
    if ( isW_ ) return fromStart ? bridgeNum+W/2 : bridgeNum+E/2 ;
    return             fromStart ? bridgeNum+N/2 : bridgeNum+S/2 ;
};


bool Bridges::isExistsWayFromEdge( int edge, DIRECT direction ){ //TESTED
    return  isExsits( edge+(direction/2));
}


int Bridges::getWayFromEdge(int eNum, DIRECT direction ){// TESTED
    if (isExistsWayFromEdge(eNum , direction )) {
        return eNum + (direction / 2);
    }
    throw std::runtime_error("Bridges::getWayFromEdge -> nie ma takiego pola");
    return -1;
}


int Bridges::getAllWaysFromEdge( int eNum ){ // tested
    int ways=0;
        if (isExistsWayFromEdge(eNum, N )){ ways+=1;  }
        if (isExistsWayFromEdge(eNum, W )){ ways+=2;  }
        if (isExistsWayFromEdge(eNum, S )){ ways+=4;  }
        if (isExistsWayFromEdge(eNum, E )){ ways+=8;  }
    return ways;
}


// ****************** WORKING HERE !!!



COORD Bridges::getCoordOfCenterBridge( int i ){
    // dimenstion bridge w:3, h:1   Board dimension w:19 h:23
    //
    //    o  -  o
    //   [e][b][e] bridge num 1
    //   [   -   ] center - (4,0){x,y}
    //


    SHORT x;
    SHORT y;
    if ( isW (i)) {
        x=i%20;
        y=i/20;
    }

    //SHORT x=edge%20;
    //SHORT y=edge/20;

    // scale
    //x*=CELL_WIDTH;
    //y*=CELL_HEIGHT;

    //fix center point
    //x++;
    return { x,y };
}









COORD Bridges::getCoordOfEdge( int edge ){
    SHORT x=edge%20;
    SHORT y=edge/20;

    // scale
    x*=CELL_WIDTH;
    y*=CELL_HEIGHT;

    //fix center point
    x++;
    return { x,y };
}








void Bridges::drawBridge(int bridgeNum) {
    COORD center;
    if ( isW(bridgeNum) ) { return drawBridgeW( bridgeNum ); }
    else  return drawBridgeH( bridgeNum );
}

void Bridges::drawBridgeW( int bridgeNum ) {
    DrawWall( bridgeNum );
    DrawDot ( bridgeNum );
    DrawMob ( bridgeNum );
}


void Bridges::DrawWall( int bridgeNum ){};
void Bridges::DrawDot ( int bridgeNum ){};
void Bridges::DrawMob ( int bridgeNum ){

    /*
     // dots
     draw.WriteColourChar( x-3,y,248 );
     draw.WriteColourChar( x-1,y,248 );
     draw.WriteColourChar( x+1,y,248 );
     draw.WriteColourChar( x+3,y,248 );

     draw.WriteColourChar( x,y,196 );

     int start = edgePosition( bridgeNum , true );
     int end = edgePosition( bridgeNum , false );
     int startWays = getAllWaysFromEdge( start );
     int endWays   = getAllWaysFromEdge( end );

     if (( startWays|( 1+2 ))==0) { drawTopLeftConner( start ); }
 */

    //cdraw.WriteColourChar( x+CELL_WIDTH*3,y,196 );

    //for (int i=-CELL_WIDTH+1;i<CELL_WIDTH*3-1;i++){
    //    cdraw.WriteColourChar( x+i,y,196 );
    //}

    //cdraw.WriteColourChar( x-CELL_WIDTH,y,250 );
    //cdraw.WriteColourChar( x+CELL_WIDTH+CELL_WIDTH-1,y,250 );



    // if (Bridges[bridgeNum+2]==' '){ cdraw.WriteColourChar( x+5,y,176 );  }
    // if (Bridges[bridgeNum-2]==' '){ cdraw.WriteColourChar( x-3,y,176 );  }

};

void Bridges::drawBridgeH( int bridgeNum ) {

    SHORT y=1+2*((bridgeNum-10)/20) ;
    SHORT x=(bridgeNum-10)%20;

    x*=CELL_WIDTH;
    y*=CELL_HEIGHT;
    //cdraw.WriteColourChar( x,y,179 );

    //cdraw.WriteColourChar( x+1,y-1,250 );
    //cdraw.WriteColourChar( x+1,y+1,250 );

    draw.WriteColourChar( x+1,  y,248 );

}






void Bridges::drawBoard() {
    //std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    //drawBridgeH(10);
    //drawBridgeH(1);

    if (false) { // wyłaczone rysowanie planszy
        for (int i = 0; i < 240; i++, i++) {
            if ( !isExsits( i ) ) { continue; }
            if ( isW(i) ) { drawBridgeH(i); }
            else { drawBridgeW(i + 1); }
        }
    }
    if (true )return;
    draw.WriteColourChar(0,0,210);
    draw.WriteColourChar(2+BW, 0 ,183);
    draw.WriteColourChar(0,    2+BH,211);
    draw.WriteColourChar(2+BW, 2+BH , 189);
    for ( int i=0; i<=BW; i++ ){
        draw.WriteColourChar(1+i,0,196);
        draw.WriteColourChar(1+i,2+BH ,196);
    }
    for ( int i=0; i<=BH; i++ ){
        draw.WriteColourChar(0    ,1+i,186);
        draw.WriteColourChar(2+BW , i+1, 186);
    }




}






