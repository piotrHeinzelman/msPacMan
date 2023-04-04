#include <iostream>

using namespace std;

int x;
int sum=0;
int mul=1;

main(){

	do {

	cout << "podaj liczbe:";
	cin >> x;

		if ( x!=0 ) {
			sum=sum+x;
			mul=mul*x;
		}
	} while(x!=0);

	cout << "suma: " << sum << ", iloczyn: " << mul;

	cin >> null;	
	return 0;
}

