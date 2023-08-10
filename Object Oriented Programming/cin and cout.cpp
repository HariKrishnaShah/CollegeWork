#include <iostream>
using namespace std;


int main(){
	int x = 10, z = 8;
	
	cout<<"Hello everyone, Welcome to my program. "<<
		"My name is Hari Krishna Shah. "<<endl;
	cout<<"The value of x is "<<x<<". "<<endl;
	
	cout<<"Insert the new value of x: ";
	cin>>x;
	cout<<"The newly stored value of x is "<<x<<". "<<endl;
	
	int &y = x;
	x = 1;
	
	cout<<"The value stored in y is "<<y<<". "<<endl;
	
	
return 0;
}


