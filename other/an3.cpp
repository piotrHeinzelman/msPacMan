#include <iostream>



main(){
	int add=1;
	int mul=-1;
	for ( int x=-1 ; x!=0 ; add+=x, mul*=x, printf("podaj liczbe:"), std::cin>>x );
	
	printf("suma:%d, iloczyn:%d",add,mul);
	
	char tmp;
	std::cin >> tmp;	
	return 0;
}

// for ( int i=0 ; i<4 ; i++) { 
//	do something
// }
//
// for ( int i=0 , int j=2; i<4 ; i++ , j++ , j++ ) { 