#include <iostream>
using namespace std;


int * compare(int &a, int &b){
	if(a>b){
		return &a;
	}
	else{
		return &b;
	}
	
	
}

int main(){
	int x, y;
	int *c;
	cout<<"Enter the two integer values: "<<endl;
	cin>>x>>y;
	
	c = compare(x,y);
	*c = 50;
	cout<<"The value of x and y is "<<x<<" , "<<y<<" . "<<endl;
	cout<<"The value of c is "<<*c<<" ."<<endl;
	
	
	
	
	
	return 0;
}
