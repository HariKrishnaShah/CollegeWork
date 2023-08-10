#include <iostream>
using namespace std;


int* compare(int *a, int *b){
	if(*a>*b){
		return a;
	}
	else{
		return b;
	}
	
	
}

int main(){
	int x, y;
	int *c;
	cout<<"Enter the two integer values: "<<endl;
	cin>>x>>y;
	
	c = compare(&x,&y);
	*compare(&x,&y) = 100;
	cout<<"The value of x and y is "<<x<<" , "<<y<<" . "<<endl;
	cout<<"The value of c is "<<*c<<" ."<<endl;
	cout<<"The value of return of function is "<<compare(&x, &y)<<" ."<<endl;
	cout<<"The value of &y is "<<&y<<" ."<<endl;
	cout<<"The value of pointer return is "<<*compare(&x,&y)<<" ."<<endl;
	
	
	
	
	
	return 0;
}
