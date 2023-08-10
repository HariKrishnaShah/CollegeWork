#include <stdio.h>
#include <string.h>
#include <malloc.h>
//Coded by Hari Krishna Shah
struct Employee_details{
	char EMP_Id[20];
	struct Name{
		char first_name[30];
		char middle_name[30];
		char last_name[30];
	}name;
	struct Address{
		char area[30];
		char city[30];
		char state[30];
	}address;
	int age;
	int salary;
	char designation[30];
};

int main(){
	struct Employee_details *Employee;
	Employee = (struct Employee_details *) (malloc(10 * sizeof(struct Employee_details)));
	
	for(int i= 0; i<10; i++){
		printf("Enter the details of employee number %d below.\n", i+1);
		printf("Enter the name of the employee below.\n");
		printf("Enter the first name: ");
		scanf("%s", &Employee[i].name.first_name);
		printf("Enter the middle name: ");
		scanf("%s", &Employee[i].name.middle_name);
		printf("Enter the last name: ");
		scanf("%s", &Employee[i].name.last_name);
		printf("Enter the area: ");
		scanf("%s", &Employee[i].address.area);
		printf("Enter the city: ");
		scanf("%s", &Employee[i].address.city);
		printf("Enter the state: ");
		scanf("%s", &Employee[i].address.state);
		printf("Enter the age: ");
		scanf("%d", &Employee[i].age);
		printf("Enter the salary: ");
		scanf("%d", &Employee[i].salary);
		printf("Enter the designation: ");
		scanf("%s", &Employee[i].designation);
		printf("\n");
	}
	
	for(int i= 0; i<10; i++){
		printf("The details of employee number %d below.\n", i+1);
		printf("Employee's full name is below.\n");
		printf("First name: %s\n", Employee[i].name.first_name);
		printf("Middle name: %s\n", Employee[i].name.middle_name);
		printf("Last name: %s\n", Employee[i].name.last_name);
		printf("Employee's Address is below.\n");
		printf("Area: %s\n", Employee[i].address.area);
		printf("City: %s\n", Employee[i].address.city);
		printf("State: %s\n", Employee[i].address.state);
		printf("Age: %d\n", Employee[i].age);
		printf("Salary: %d\n", Employee[i].salary);
		printf("Designation: %s\n", Employee[i].designation);
		printf("\n");
	}
	
	return 0;
}
