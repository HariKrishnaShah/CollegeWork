#include <iostream>
#include <stdbool.h>
using namespace std;
//Coded by Hari Krishna Shah
bool isprime(int num);

int main(){
	int num;
	char option;
	bool prime;
	do{
		cout<<"Enter a number: ";
		cin>>num;
		prime = isprime(num);
		if(prime){
			cout<<"The number "<<num<<" is a prime number."<<endl;
		}
		else{
			cout<<"The number "<<num<<" is not a prime number."<<endl;
		}
		cout<<"\nEnter q to quit the program or any other key to run the program again: ";
		cin>>option;
		cout<<endl;
}
	while(option != 'q');
	cout<<"Thank you for using the program."<<endl;
	return 0;
}

bool isprime(int num){
	int count = 0;
	for(int i = 1; i<=num; i++){
		if(num %i == 0){
			count ++;
		}
	}
	
	if(count == 2){
		return true;
	}
	
	return false;
}
