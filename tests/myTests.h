/**
 *  Klasa do uruchamiania zestawów testów,
 *  uruchamiana przez MAIN()
 *  dla
 */
#include "commTest.h"
#include "servTest.h"

class myTests {
    private:

    public:
    void run(){
           commTest ct;  ct.run();
           servTest ct;  ct.run();
    }
};
