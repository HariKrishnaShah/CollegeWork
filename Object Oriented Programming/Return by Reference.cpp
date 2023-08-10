#include <iostream>
using namespace std;


int & compare(int &a, int &b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}

int main(){
	int x, y;
	int c = 100;
	cout<<"Enter the two integer values: "<<endl;
	cin>>x>>y;
		
	compare(x, y) = 100;
	cout<<"The value of x and y is "<<x<<" , "<<y<<" . "<<endl;
	cout<<"The value returned by function is "<<compare(x, y)<<endl;
	
	return 0;
}
