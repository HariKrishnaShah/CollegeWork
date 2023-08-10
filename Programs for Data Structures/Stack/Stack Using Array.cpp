#include <stdio.h>
#define MAX 50

int stack[MAX], top = -1;
void push(int stack[], int data);
int pop(int stack[]);
int peek(int stack[]);
void display_all(int stack[]);
int main(){
	int option;
	int data;
	do{
	printf("\t\t\tThis program is created by Hari Krishna Shah !!!\n");
	printf("Welcome to the main menu.");
	printf("Enter an option from the menu below\n \
	Enter 1 to push new element to the stack\n \
	Enter 2 to pop or delete the topmost element of the stack\n \
	Enter 3 to peek or read the topmost element of the stack\n \
	Enter 4 to display all the elements of the stack\n \
	Enter -1 to quit the program\n");
	printf("Enter your option here: ");
	scanf("%d", &option);
	
	switch(option){
		case -1:{
			break;
		}
		case 1:{
				printf("Enter the value to be pushed to the stack: ");
				scanf("%d", &data);
				push(stack, data);
			break;
		}
		case 2:{
				data = pop(stack);
				if(data != -1){
					printf("The data %d has been deleted successfully.\n", data);
				}
			break;
		}
		case 3:{
			data = peek(stack);
			if(data != -1){
				printf("The data stored at the top of the stack is %d.\n", data);
			}
			break;
		}
		case 4:{
			display_all(stack);
			break;
		}
		default:{
			printf("Enter a valid option and try again.\n");
			break;
		}
			
		
	}
	printf("\n");
	}
	while(option != -1);
	printf("Thank you for using the progam.\n");
	
}

void push(int stack[], int data){
	if(top == MAX - 1){
		printf("The stack is full.\n");
	}
	else{
		top += 1;
		stack[top] = data;
		printf("The data %d has been added to the stack successfully.\n", data);
	}
}

int pop(int stack[]){
	int data;
	if(top == -1){
		printf("The stack is empty. Add some elements to the stack first.\n");
		return -1;
	}
	else{
		data = stack[top];
		top--;
		return data;
	}
}
int peek(int stack[]){
	int data;
	if(top == -1){
		printf("The stack is empty. Add some elements to the stack first.\n");
		return -1;
	}
	else{
		data = stack[top];
	}
}
void display_all(int stack[]){
	if(top == -1){
		printf("The stack is empty. Add some elements to the stack first.\n");
	}
	else{
		printf("The elements of the stack are: ");
		for(int i = top; i>=0; i--){
			printf("%d ", stack[i]);
		}
	}
}
