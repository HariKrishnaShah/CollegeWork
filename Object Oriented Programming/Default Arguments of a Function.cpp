#include <iostream>
using namespace std;

void zook(int a, int b = 4, int c = 8);




int main(){
	int x = 25, y = 15, z = 18;
	printf("The value of x is %d, y is %d and z is %d.", x, y, z);
	zook(x);
	
	
	
	return 0;
}

void zook(int a, int b, int c){
	printf("\n\nThe value of a is %d, b is %d and c is %d.", a, b, c);
	
	
}
