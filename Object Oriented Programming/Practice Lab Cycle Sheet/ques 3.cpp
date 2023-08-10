#include <iostream>
#include <string>
#include<cstring>
using namespace std;
int compare(int a, int b, int c);
double compare(double A, double B, double C);
string &compare(string a1, string b2, string c3);

int main(){
	int option = 0;
	while(option != -1){
		cout<<"Enter an option from the menu below.\n \
		Enter 1 to compare three integers\n \
		Enter 2 to compare three doubles\n \
		Enter 3 to compare three strings\n \
		Enter -1 to quite the program\n";
		cout<<"Enter your option here: ";
		cin>>option;
		switch(option){
			case 1:{
				int a, b, c, largest_int;
				cout<<"Enter three integers: ";
				cin>>a>>b>>c;
				largest_int = compare(a, b, c);
				cout<<"The largest integer is "<<largest_int<<" ."<<endl;
				break;
			}
			case 2:{
				double A, B, C, largest_double;
				cout<<"Enter three doubles: ";
				cin>>A>>B>>C;
				largest_double = compare(A, B, C);
				cout<<"The largest double is "<<largest_double<<" ."<<endl;
				break;
			}
			case 3:{
				string a1, b2, c3, largest;
				cout<<"Enter three strings separated by whitespace: ";
				cin>>a1>>b2>>c3;
				largest = compare(a1, b2, c3);
				cout<<"The largest string is "<<largest<<" ."<<endl;
				break;
			}
			default:
				cout<<"Enter a valid option and try again."<<endl;
		}
		cout<<"\n"<<endl;
	}
}
int compare(int a, int b, int c){
	int large;
	large = (a>b)?(a>c?a:c): (b>c ? b: c);
	return large;
}
double compare(double A, double B, double C){
	int large;
	large = (A>B)?(A>C?A:C): (B>C ? B: C);
	return large;
}
string &compare(string a1, string b2, string c3){
	if(a1.compare(b2)>0){
		if(a1.compare(c3)>0){
			return a1;
		}
		else{
			return c3;
		}
	}
	else{
		if(b2.compare(c3)>0){
			return b2;
		}
		else{
			return c3;
		}
	}
}
