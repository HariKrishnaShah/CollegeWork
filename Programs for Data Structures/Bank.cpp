#include <stdio.h>
#include <string.h>

struct Bank{
	long long int acc_no;
	char name[100];
	float balance;
};

struct Bank customer[200];
static int customer_count = -1;

void add();
int search(long long int acc);
void deposit(long long int req_acc);
void withdraw(long long int req_acc);
void check_below_hundred();

int main(){
	int option;
	long long int req_acc;
	while(option != -1){
		printf("\t***Welcome to the Manas Bank.***\n");
		printf("Please choose your option from the menu below\n \
		Enter 0 to add new bank account details\n \
		Enter 1 to see your bank details: \n \
		Enter 2 to deposit money in your account\n \
		Enter 3 to withdraw money from your bank\n \
		Enter 4 to see all the bank account with balance less than 100\n \
		Enter -1 to exit\n");
		printf("Enter your option here: ");
		scanf("%d", &option);
		
		switch(option){
			case -1:{
				break;
			}
			case 0:{
				if(customer_count<199){
					add();
				}
				else{
					printf("The array of bank structure is full.\n Can't add anymore customers.\n");
				}
				break;
			}
			case 1:{
				printf("Enter your bank account number: ");
				scanf("%lld", &req_acc);
				search(req_acc);
				break;
			}
			case 2:{
				printf("Enter your bank account number: ");
				scanf("%lld", &req_acc);
	 			deposit(req_acc);
				break;
			}
			case 3:{
				printf("Enter your bank account number: ");
				scanf("%lld", &req_acc);
				withdraw(req_acc);
				break;
			}
			case 4:{
				check_below_hundred();
				break;
			}
		}
		printf("\n");

	}
	return 0;
}

void add(){
	long long int temp_acc;
	printf("Enter the name of customer: ");
	scanf("%c");
	gets(customer[(customer_count + 1)].name);
	printf("Please Enter an account number for your bank account: ");
	scanf("%lld", &temp_acc);
	customer[customer_count + 1].acc_no = temp_acc;
	printf("Enter the first amount you want to deposit: ");
	scanf("%f", &customer[customer_count + 1].balance);
	printf("Bank Account created Successfully.\n");
	customer_count = customer_count + 1;
}

int search(long long int acc){
	int flag = 0, i = 0;
	for(; i<=customer_count; i++){
		if(customer[i].acc_no == acc){
			flag = 1;
			break;
		}
	}
	if(flag == 0){
		printf("\nSorry, the requested account was not found in the database.\n");
		return 0;
	}
	else{
		printf("Name: %s\n", customer[i].name);
		printf("Account number: %lld\n", customer[i].acc_no);
		printf("Balance: %f\n", customer[i].balance);
		return 1;
	}
}

void deposit(long long int req_acc){
	int flag = 0, i = 0;
	float deposit_amt;
	for(; i<=customer_count; i++){
		if(customer[i].acc_no == req_acc){
			flag = 1;
			break;
  		}
	}
	if(flag == 0){
		printf("\nSorry, the requested account was not found in the database.\n");
	}
	else{
		printf("Enter the amount you want to deposit: ");
		scanf("%f", &deposit_amt);
		customer[i].balance += deposit_amt;
	}
}
void withdraw(long long int req_acc){
	int flag = 0, i = 0;
	float withdraw_amt;
	for(; i<=customer_count; i++){
		if(customer[i].acc_no == req_acc){
			flag = 1;
			break;
		}
	}
	if(flag == 0){
		printf("\nSorry, the requested account was not found in the database.\n");
	}
	else{
		printf("Enter the amount you want to withdraw: ");
		scanf("%f", &withdraw_amt);
		if(customer[i].balance>= withdraw_amt){
			customer[i].balance -= withdraw_amt;
		}
		else{
			printf("Sorry, there isn't sufficient balance.");
		}
	}
}
void check_below_hundred(){
	int count = 0;
	printf("Below is the result for detail of people with less than 100 balance.\n");
	for(int i = 0; i<=customer_count; i++){
		if(customer[i].balance<100){
			count++;
			printf("Below is detail for count number %d\n", count);
			printf("Name: %s\n", customer[i].name);
			printf("Account number: %lld\n", customer[i].acc_no);
			printf("Balance: %f\n", customer[i].balance);
		}
	}
	if(count == 0){
		printf("Currently, none customer have less than 100 balance in their account.\n");
	}
}
