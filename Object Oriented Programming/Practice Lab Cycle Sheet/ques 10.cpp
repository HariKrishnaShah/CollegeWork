/*
Write a recursive function to multiply two integers.
*/
#include <iostream>
using namespace std;

int multiplication(int x, int y);
int main(){
	int a, b, multi;
	cout<<"Enter the value for two integers: ";
	cin>>a>>b;
	multi = multiplication(a, b);
	cout<<"The product of the numbers "<<a<<" and "<<b<<" is "<<multi<<"."<<endl;
}

int multiplication(int x, int y){
	if(x<y){
		return multiplication(y,x);
	}
	else if(y != 0){
		return (x+multiplication(x, y-1));
	}
	else{
		return 0;
	}
}


