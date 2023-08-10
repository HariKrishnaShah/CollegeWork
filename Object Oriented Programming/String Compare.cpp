/*Write a C++ function called “zstrcmp” to compare one string with another string or compare first ‘n’ characters of one string with another string.
Use default arguments and Do not overload the function. “zstrcmp” function must return an integer which has the same interpretation as that of  “strcmp” in C. */


#include <iostream>
using namespace std;

//Without using inbuilt function.
int zstrcmp(char *string1, char *string2, int c_size);

int main(){
	char str1[100], str2[100];
	int c_size, compare_value;
	cout<<"Enter the first string: ";
	cin>>str1;
	
	cout<<"Enter the second string: ";
	cin>>str2;
	
	
	cout<<"Enter the number of characters you want to compare: ";
	cin>>c_size;
	
	compare_value = zstrcmp(str1, str2, c_size);
	
	if(compare_value == 0){
		cout<<"The strings are equal."<<endl;
	}
	if(compare_value>0){
		cout<<"The string1 is greater than the string2."<<endl;
	}
	if(compare_value<0){
		cout<<"The string2 is greater than the string1."<<endl;
	}
	
	cout<<"The value of compare_value is "<<compare_value<<" ."<<endl;
	
	return 0;
}

int zstrcmp(char *string1, char *string2, int c_size){	
int c;
	for(int i = 0; i<c_size; i++){
		if(*string1 != '\0' && *string2 != 0){
			c = *string1 - *string2;
			
			if(c==0){
				*string1 += 1;
				*string2 += 1;
			}
			else{
				return c;
			}	
			
	}
	
}
	return c;
}

