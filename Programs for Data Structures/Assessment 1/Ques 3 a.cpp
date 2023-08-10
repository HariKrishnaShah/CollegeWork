//Hari Krishna Shah
//VIT ID: 21BCS0167

/* 3.
a) Create a structure named company which has name, address, phone and no. Of Employee as
member variables. Read name of company, its address, phone and no. Of Employee. Finally
display these members’ value. */

#include <stdio.h>


int main(){
	struct company{
		char name[100];
		char address[100];
		long long int phone;
		int no_employees;
	};
	
	struct company c1;
	printf("Please Enter the details for the company C1 below.");
	printf("\nEnter the name of the company: ");
	gets(c1.name);
	printf("Enter the address of the company: ");
	gets(c1.address);
	printf("Enter the phone number of the company: ");
	scanf("%lld", &c1.phone);
	printf("Enter the number of employess in the company: ");
	scanf("%d", &c1.no_employees);
	
	printf("\nThe details of the company c1 are given below:");
	printf("\nThe name of the company is %s.", c1.name);
	printf("\nThe address of the company is %s.", c1.address);
	printf("\nThe phone number of the company is %lld.", c1.phone);
	printf("\nThe number of employess in the company is %d.", c1.no_employees);
	return 0;
}
