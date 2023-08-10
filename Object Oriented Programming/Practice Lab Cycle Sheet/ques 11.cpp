/*
Write a recursive function to find the sum of first 'N' Natural numbers.
*/
#include <iostream>
using namespace std;
int sum(int num);
int main(){
	int num, total;
	cout<<"Enter a number: ";
	cin>>num;
	total = sum(num);
	cout<<"The sum of the first natural numbers upto number "<<num<<" is "<<total<<" ."<<endl;
}

int sum(int num){
	if(num == 0){
		return 0;
	}
	else{
		return (num + sum(num-1));
	}
}
