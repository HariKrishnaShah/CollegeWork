#include <iostream>
using namespace std;
void search(int x, int array[], int size);
void search(char x, char string[], int size);
void search(float x, float f_array[], int size);

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
	cout<<"Enter the integer to search: ";
	cin>>integer;
	search(integer, array, size1);
	cout<<"Enter the size of char array: ";
	cin>>size2;
	cout<<"Enter the elements of the character array: ";
	for(int i = 0; i<size2; i++){
		cin>>string[i];
	}
	cout<<"Enter the character to search: ";
	cin>>character;
	search(character, string, size2);
	cout<<"Enter the size of float array: ";
	cin>>size3;
	cout<<"Enter the elements of the float array: ";
	for(int i = 0; i<size2; i++){
		cin>>f_array[i];
	}
	cout<<"Enter the float to search: ";
	cin>>floats;
	search(floats, f_array, size3);
}

void search(int x, int array[], int size){
	int flag = 0;
	for(int i = 0; i<size; i++){
		if(array[i] == x){
			cout<<"The searched integer is available at the index "<<i<<" .\n\n"<<endl;
			flag += 1;
		}
	}
	if(flag == 0){
		cout<<"The searched element was not found in the array.\n\n"<<endl;
	}
}
void search(char x, char string[], int size){
	int flag = 0;
	for(int i = 0; i<size; i++){
		if(string[i] == x){
			cout<<"The searched character is available at the index "<<i<<" .\n\n"<<endl;
			flag += 1;
		}
	}
	if(flag == 0){
		cout<<"The searched element was not found in the array.\n\n"<<endl;
	}
}
void search(float x, float f_array[], int size){
	int flag = 0;
	for(int i = 0; i<size; i++){
		if(f_array[i] == x){
			cout<<"The searched float is available at the index "<<i<<" .\n\n"<<endl;
			flag += 1;
		}
	}
	if(flag == 0){
		cout<<"The searched element was not found in the array.\n\n"<<endl;
	}
}
