#include <iostream>

using namespace std;

int x;
int sum=0;
int mul=1;

main(){
	
	cout << "podaj liczbe:";

	while( cin>>x , x!=0) {
		sum+=x;
		mul*=x;
		cout << "podaj liczbe:";	
		};
	

	cout << "suma: " << sum << ", iloczyn: " << mul;

	string tmp;
	cin >> tmp;	
	return 0;
}

