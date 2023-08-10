//Hari Krishna Shah
//VIT ID: 21BCS0167

/* 3.Create a structure named company which has name, address, phone and no. Of Employee as
member variables. Pass the structures defined in Question into a function and read the structure member and
display the values.
*/

#include <stdio.h>
struct company{
		char name[100];
		char address[100];
		long long int phone;
		int no_employees;
	};
void readAndwrite(struct company *c){
	printf("Please Enter the details for the company C1 below.");
	printf("\nEnter the name of the company: ");
	gets(c->name);
	printf("Enter the address of the company: ");
	gets(c->address);
	printf("Enter the phone number of the company: ");
	scanf("%lld", &c->phone);
	printf("Enter the number of employess in the company: ");
	scanf("%d", &c->no_employees);
	
	printf("\nThe details of the company c1 is given below.");
	printf("\nThe name of the company is %s.", c->name);
	printf("\nThe address of the company is %s.", c->address);
	printf("\nThe phone number of the company is %lld.", c->phone);
	printf("\nThe number of employess in the company is %d.", c->no_employees);
	
}

int main(){
	struct company c1;
	readAndwrite(&c1);
	return 0;
}

