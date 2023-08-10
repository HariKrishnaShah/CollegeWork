#include <stdio.h>
#include <malloc.h>

struct node{
	int data;
	struct node *next;
};

int main(){
	int z;
	char a;
	struct node *start, *ptr, *tail;
	start = (struct node *) (malloc(sizeof(struct node)));
	ptr = start;
	
	tail = (struct node *) (malloc(sizeof(struct node)));
	start->next = tail;
	start->data = 15;
	tail->data = 10;
	
	z = start->next->data;
	printf("The value of z is %d.", z);
	getchar();
	return 0;
}
