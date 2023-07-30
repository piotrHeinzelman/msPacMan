#include <iostream>
#include <set>
#include <vector>

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




	class CTowar {
	private:
	  int ilosc;
	  std::string nazwa;
	public:
	  CTowar() { nazwa = ""; ilosc = 0; }
	  void setNazwa(std::string _n) { nazwa = _n; }
	  void setIlosc(int _i) { ilosc = _i; }
	  void pisz() { std::cout << nazwa << ", ilosc: " << ilosc; }
	  // uzupełnić ...
	  CTowar operator +( int i ) const  {
		CTowar tmp = *this; tmp.ilosc+=i; return tmp;
	  }

	};







int main(){
   Bear bear;
		std::cout << "& bear: " << & bear << "\r\n";

   Bear* Tbear = & bear;

   bear.lewe.setName("gray");
   bear.prawe.setName("red");
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


	std::cout << "bear.toString() " <<  bear2.toString() << "\r\n";





	std::set<std::string> dane;
	dane.insert("one");
	dane.insert("two");
	dane.insert("three");

	for ( auto item : dane ){
	std::cout << item << "\r\n";
	}

	auto item = dane.begin() ;
	auto iEnd = dane.end() ;
	for (  ; item != iEnd  ; item++ ){  std::cout << *item;	}




	  CTowar a;
	  a.setNazwa("jaja");
	  a.setIlosc(5);
	  CTowar b = a+5;
	  b.pisz();
	  a.pisz();


   return 0;
}
