/**
 *  Klasa do uruchamiania zestawów testów,
 *  uruchamiana przez MAIN()
 *  dla
 */
#include "../comm.h"

class commTest {
    private:

    public:
    void run(){
        comm com;
        com.connect( "wpolityce.pl", 80 );


    }
};
