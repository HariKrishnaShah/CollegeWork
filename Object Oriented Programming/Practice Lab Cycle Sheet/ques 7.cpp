/*4.	Write a C++ function called "zstrcpy" to copy one string to another
or copy first 'n' characters of one string into another. Use default arguments
and Do not overload the function.
*/
#include <iostream>
using namespace std;
void ztrcpy(char st1[50], char str2[50]);

int main(){
	char str1[50], str2[50];
	cout<<"Enter the value to be stored in string 1: ";
	cin>>str1;
	cout<<"Enter the value to be stored in string 2: ";
	cin>>str2;
	cout<<"The value of string1 before calling ztrcpy function is "<<str1<<" ."<<endl;
	cout<<"The value of string2 before calling ztrcpy function is "<<str2<<" ."<<endl<<endl;
	ztrcpy(str1, str2);
	cout<<"The value of string1 after calling ztrcpy function is "<<str1<<" ."<<endl;
}

void ztrcpy(char str1[50], char str2[50]){
	char temp[50];
	for(int i = 0; i<50; i++){
		str1[i] = str2[i];
	}
	
	
}

