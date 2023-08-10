#include <stdio.h>

struct Bank{
	int acc_no;
	char name[100];
	float balance;
};
void withdraw(int acc_no, int size);
void deposit(int acc_no, int size);
struct Bank customer[200];

int main(){
	int size, acc_no, option, flag = 0;
	printf("Enter the number of customers: ");
	scanf("%d", &size);
	
	for(int i = 0; i<size; i++){
		printf("Enter the detail of customer number %d below: \n", i+1);
		printf("Enter the name of customer: ");
		scanf("%s", &customer[i].name);
		printf("Enter the account number of customer: ");
		scanf("%d", &customer[i].acc_no);
		printf("Enter the first amount you want to deposit: ");
		scanf("%f", &customer[i].balance);
  		printf("Bank Account created Successfully.\n\n");
	}
	
	printf("\n");
	printf("All memebers with balance less than 100 are given below: \n");
	
	for(int i = 0; i<size; i++){
		if(customer[i].balance<100){
			printf("Name: %s\n", customer[i].name);
			printf("Account number: %d\n", customer[i].acc_no);
			printf("Balance: %f\n", customer[i].balance);
			printf("\n");
		}
	}
	
	printf("Enter your acc_no: ");
	scanf("%d", &acc_no);
	
	printf("Enter 1 to deposit or 0 to withdraw: ");
	scanf("%d", &option);
	switch(option){
		case 0:{
			withdraw(acc_no, size);
			break;
		}
		case 1:{
			deposit(acc_no, size);
	}
	
	return 0;
}
}
void withdraw(int acc_no, int size){
				int flag = 0;
				float amt;
				for(int i = 0; i<size; i++){
					if(customer[i].acc_no == acc_no){
						flag = 1;
						printf("Enter the amount to withdraw: ");
						scanf("%f", &amt);
						if(amt<= customer[i].balance){
							customer[i].balance -= amt;
							printf("Congrats ! The amout withdrawn successfully");
							printf("New balance is %f.", customer[i].balance);
						}
						else{
							printf("Insufficient Balance\n");
						}
						break;
					}
				}
				if(flag ==0){
					printf("Account not found.\n");
				}
}
void deposit(int acc_no, int size){
				int flag = 0;
				float amt;
				for(int i = 0; i<size; i++){
					if(customer[i].acc_no == acc_no){
						flag = 1;
						printf("Enter the amount to deposit: ");
						scanf("%f", &amt);
						customer[i].balance += amt;
						printf("Amount deposited successfully.\n");
						printf("New balance is %f.", customer[i].balance);
						break;
					}
				}
				if(flag == 0){
					printf("Account not found.\n");
				}
}



