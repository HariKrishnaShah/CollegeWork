/*
Write a recursive function to calculate the Fibonacci value.
*/

#include <iostream>
using namespace std;

int fibonacci_value(int index);
int main(){
	int count, index = 0;
	cout<<"Enter the number of fibonacci values you want: ";
	cin>>count;
	cout<<"The fibonacci series is: ";
	for(int i = 1; i<=count; i++){
		cout<<fibonacci_value(index)<<" ";
		index++;
	}
	return 0;
}

int fibonacci_value(int index){
	if(index == 0){
		return 0;
	}
	else if(index == 1){
		return 1;
	}
	else{
		return (fibonacci_value(index-1)+fibonacci_value(index-2));
	}
}
