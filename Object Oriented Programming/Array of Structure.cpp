#include <iostream>
#include <string.h>
using namespace std;


int main()
{
	int temp = 0;
	struct student{
		char name[100];
		int roll;
		float marks[3];
		float total;
		float average;
		char result[20];	
	};
	
	struct student s[2];
	
	for(int i = 0; i<10; i++){
		cout<<"Enter the details of student number "<<i+1<<" below."<<endl;
		cout<<"Enter the name: ";
		cin>>s[i].name;
		cout<<"Enter the roll number: ";
		cin>>s[i].roll;
		strcpy(s[i].result, "PASS");
		
		
		for(int j = 1; j<=3; j++){
			cout<<"Enter the marks for subject number "<<j<<" :";
			cin>>s[i].marks[j];
			if(s[i].marks[j]<50){
				strcpy(s[i].result, "FAIL");
			}
			temp = temp + s[i].marks[j];
		}
		
		s[i].total = temp;
		temp = 0;
		s[i].average = s[i].total/3;
		cout<<endl;
			
	}
	
	for(int i = 0; i<10; i++){
		cout<<"The details for student number "<<i+1<<" is given below."<<endl;
		cout<<"Name: "<<s[i].name<<endl;
		cout<<"Roll number: "<<s[i].roll<<endl;
		for(int j = 1; j<=3; j++){
			cout<<"Subject "<<j<<" marks: "<<s[i].marks[j]<<endl;	
		}
		cout<<"Total marks: "<<s[i].total<<endl;
		cout<<"Average marks: "<<s[i].average<<endl;
		cout<<"Result: "<<s[i].result<<endl;
		cout<<endl;
		
	}
	
	
	
	
	
	
	
	
	
	return 0;
}
