#include <iostream>
#include <malloc.h>
using namespace std;

void calculate(int &maximum, int &minimum, int *array, int size);

int main(){
	int max, min, size, *array;
	cout<<"Enter the size of the array: ";
	cin>>size;
	
	array = (int *) (malloc(size * (sizeof(int))));
	cout<<"Enter the array elements : ";
	for(int i = 0; i<size; i++){
		cin>>array[i];
	}
	
	calculate(max, min, array, size);
	cout<<"The maximum value stored in the array is "<<max<<" ."<<endl;
	cout<<"The minimum value stored in the array is "<<min<<" ."<<endl;

	return 0;
}

void calculate(int &maximum, int &minimum, int *array, int size){
	maximum = array[0];
	minimum = array[0];
	for(int i = 0; i<size; i++){
			if(array[i]>maximum){
				maximum = array[i];
			}
	}
	for(int i = 0; i<size; i++){
			if(array[i]<minimum){
				minimum = array[i];
			}
	}
	
}
