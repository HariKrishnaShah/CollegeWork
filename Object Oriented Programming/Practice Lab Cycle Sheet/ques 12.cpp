/*
Write a recursive function to Linear Search an array of 'N' integers.
*/
#include<iostream>
using namespace std;
int search_int(int array[], int search, int size);
int main(){
	int size = 0, search;
	int flag = -1;
	cout<<"Enter the size of the array: ";
	cin>>size;
	int array[size];
	cout<<"Enter the array elements: ";
	for(int i = 0; i<size; i++){
		cin>>array[i];
	}
	cout<<endl;
	cout<<"The array elements are: ";
	for(int i = 0; i<size; i++){
		cout<<array[i]<<" ";
	}
	cout<<endl<<endl;
	cout<<"Enter an integer to search in the array: ";
	cin>>search;
	flag = search_int(array, search, size);
	if(flag == -1){
		cout<<"The searched integer "<<search<<" was not found in the array."<<endl;
	}
	else{
		cout<<"The searched integer "<<search<<" was found in the array at index "<<flag<<" ."<<endl;
	}
}

int search_int(int array[], int search, int size){
	int again;
	size--;
	if(size>= 0){
		if(array[size]==search){
			return size;
		}
		else{
			again = search_int(array, search, size);
		}
	}
	else{
		return -1;
	}
	return again;
}
