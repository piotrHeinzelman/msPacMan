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
        //std::cout << com.connect( "127.0.0.1", 80 ) << "\r\n";
        int socked_id = com.connect( "127.0.0.1", 8080 );

        std::cout << socked_id;
        char buf[512];
        sprintf(buf, "HEL#janic#\n");
        sprintf(buf, "/&a=1");
        com.se_nd( buf );
    }
};
