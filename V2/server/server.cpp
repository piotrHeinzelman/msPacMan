#include <iostream>

class Eye{
   private:
   std::string _name;

   public:
   Eye( std::string name="blue"  ){ _name = name; }


   std::string getName(){ return "oczko " + _name + "\r\n"; };

   void setName( std::string name="blue" ){
//      _name = name;
      this->_name = name;
      (*this)._name = name;
   }
};


class Bear{
   public:
   Eye lewe;
   Eye prawe;

};


int main(){
   Bear bear = Bear();
   bear.lewe = Eye();
   bear.prawe = Eye("red");
   std::cout << bear.lewe.getName();
   std::cout << bear.prawe.getName();



   Bear* Wbear = new Bear();
   std::cout << Wbear->lewe.getName();
   std::cout << Wbear->prawe.getName();


   return 0;
}
