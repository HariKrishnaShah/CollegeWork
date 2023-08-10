#include <iostream>
using namespace std;
void sort(int array[], int size);
void sort(char string[], int size);
void sort(float f_array[], int size);

int main(){
	int size1 = 0, size2 = 0, size3 = 0;
	int integer;
	char character;
	float floats;
	int array[size1];
	char string[size2];
	float f_array[size3];

	cout<<"Enter the size of int array: ";
	cin>>size1;
	cout<<"Enter the elements of the int array: ";
	for(int i = 0; i<size1; i++){
		cin>>array[i];
	}
	cout<<"The elements of the unsorted array are: ";
	for(int i = 0; i<size1; i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
	sort(array, size1);
	cout<<"The elements of the sorted array are: ";
	for(int i = 0; i<size1; i++){
		cout<<array[i]<<" ";
	}
	cout<<endl<<endl;
	
	cout<<"Enter the size of char array: ";
	cin>>size2;
	cout<<"Enter the elements of the character array: ";
	for(int i = 0; i<size2; i++){
		cin>>string[i];
	}
	cout<<"The elements of the unsorted array are: ";
	for(int i = 0; i<size2; i++){
		cout<<string[i]<<" ";
	}
	cout<<endl;
	sort(string, size2);
	cout<<"The elements of the sorted array are: ";
	for(int i = 0; i<size2; i++){
		cout<<string[i]<<" ";
	}
	cout<<endl<<endl;

	cout<<"Enter the size of float array: ";
	cin>>size3;
	cout<<"Enter the elements of the float array: ";
	for(int i = 0; i<size2; i++){
		cin>>f_array[i];
	}
	cout<<"The elements of the unsorted array: ";
	for(int i = 0; i<size2; i++){
		cout<<f_array[i];
	}
	cout<<endl;
	sort(f_array, size3);
	cout<<"The elements of the sorted array: ";
	for(int i = 0; i<size2; i++){
		cout<<f_array[i]<<endl;
	}
	cout<<endl;
	return 0;
}
void sort(int array[], int size){
	int temp;
	for(int i = 0; i<size; i++){
		for(int j = i+1; j<size; j++){
			if(array[i]>array[j]){
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
		}
}
void sort(char string[], int size){
	char temp;
	for(int i = 0; i<size; i++){
		for(int j = i+1; j<size; j++){
			if(string[i]>string[j]){
				temp = string[i];
				string[i] = string[j];
				string[j] = temp;
			}
		}
		}
}
void sort(float f_array[], int size){
	float temp;
	for(int i = 0; i<size; i++){
		for(int j = i+1; j<size; j++){
			if(f_array[i]>f_array[j]){
				temp = f_array[i];
				f_array[i] = f_array[j];
				f_array[j] = temp;
			}
		}
		}
}

