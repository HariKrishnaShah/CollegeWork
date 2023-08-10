#include <stdio.h>
#include <malloc.h>

int main(){
	struct node{
		int data;
		struct node *next;
	};
	
	struct node *head;
	
	head = (struct node *) (malloc(sizeof(struct node)));
	
	head->data = 15;
	printf("The data value of head of list is %d.", head->data);
	
	
	
	
	
	
	return 0;
}
