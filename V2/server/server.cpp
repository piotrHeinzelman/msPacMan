#include <iostream>

class Eye{
   private:
   std::string _name;

   public:
   Eye( std::string name="blue"  ){ _name = name; }


   std::string getName(){ return "oczko : " + _name + "\r\n"; };

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

   std::string toString(){ return "Bear: \r\nprawe " + prawe.getName() + "lewe " + lewe.getName();  }
};


int main(){
   Bear bear;
		std::cout << "& bear: " << & bear << "\r\n";
        bear = Bear();
		std::cout << "& bear: " << & bear << "\r\n";

   Bear* Tbear = & bear;

//   Bear bear = Bear();
   bear.lewe = Eye();
   bear.prawe = Eye("red");
   std::cout << bear.lewe.getName();
   std::cout << bear.prawe.getName();



   Bear* Wbear = new Bear();
         Wbear->lewe.setName("yellow");
         Wbear->prawe.setName("brown");
   std::cout << Wbear->toString();
   std::cout << (*Wbear).toString();
   std::cout << Wbear->lewe.getName();
   std::cout << Wbear->prawe.getName();



   Bear bear2 = * new Bear();
        bear2.lewe.setName("yellow");
        bear2.prawe.setName("brown");

	std::cout << "\r\n\r\n*****************\r\n";
	std::cout << "bear : " <<  & bear << "\r\n";
	std::cout << "Wbear: " << Wbear << "\r\n";
//	std::cout << "Wbear: *" << * Wbear << "\r\n";
	std::cout << "Wbear: &" << ( & Wbear ) << "\r\n";
	std::cout << "bear2: " <<   & bear2 << "\r\n";

   return 0;
}
