/*
Write a C++ program to illustrate the usage of function call operator as lvalue in an assignment statement. (Note: Return By Reference)
*/

#include <iostream>
using namespace std;


int & compare(int *a, int *b){
	if(*a>*b){
		return *a;
	}
	else{
		return *b;
	}

}

int main(){
	int x, y;
	cout<<"Enter the two integer values: ";
	cin>>x>>y;
	cout<<"The maximum value is "<<compare(&x, &y)<<" .\n"<<endl;
	cout<<"Now, the value of variable with the maximum value is replaced by 100 using return by reference below.\n"<<endl;
	int c = 100;
	compare(&x, &y) = c;
	cout<<"The value of x and y is "<<x<<" , "<<y<<" . "<<endl;

	return 0;
}
