#include <iostream>
using namespace std;
#include <malloc.h>

int main(){
	int *array, arr_size;
	cout<<"Enter the number of elements to store in the array: ";
	cin>>arr_size;
	array = new int[arr_size];
	cout<<"Enter the elements to store in the array: ";
	for(int i = 0; i<arr_size; i++){
		cin>>array[i];
	}
	cout<<"The elements stored in the array are: ";
	for(int i = 0; i<arr_size; i++){
		cout<<array[i]<<" ";
	}
	
	delete array;


return 0;
}
