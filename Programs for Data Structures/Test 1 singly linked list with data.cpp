#include <stdio.h>
#include <malloc.h>
//Coded By Hari Krishna Shah
struct node{
		char regno[20];
		char name[50];
		struct node *next;
};
struct node *insert_end(struct node *);
struct node *display(struct node *);
struct node *add_head(struct node *);
struct node *delete_head(struct node *);
struct node *delete_end(struct node *);
struct node *add_in_middle(struct node *);
struct node *delete_the_middle(struct node *);
struct node get_details();
int main(){
	int option = 0;
	struct node *start = NULL;

	while(option != -1){
		printf("\t\t\tThis program is created by Hari Krishna Shah.\n");
		printf("Welcome to the Main-Menu !\n\
		Enter 1 to insert node at end.\n\
		Enter 2 to insert a node in the middle\n \
		Enter 3 to insert node in the front\n \
		Enter 4 to delete the first node\n \
		Enter 5 to delete the last node\n \
		Enter 6 to delete the middle node \n \
		Enter 7 to display linked list.\n\
		Enter -1 to exit the program\n");
		printf("\nEnter your option here: ");
		scanf("%d", &option);

		switch(option){
			case 1:
				start = insert_end(start);
				break;

			case 2:
				start = add_in_middle(start);
				break;

			case 3:
				start = add_head(start);
				break;
			case 4:
				start = delete_head(start);
				break;
			case 5:
				start = delete_end(start);
				break;
			case 6:{
				start = delete_the_middle(start);
				break;
			}
			case 7:{
				start = display(start);
				break;
			}
			
			case -1:
				break;
			default:
				printf("Please enter a valid option and try again !!!\n\n");
				break;
		}
		printf("\n");
	}
	printf("Thank you for using the program.\n");
	printf("The program exited successfully.\n");
	return 0;
}



struct node *insert_end(struct node *start){
	struct node *ptr, *new_node;
	new_node = (struct node *) (malloc(sizeof(struct node)));
	ptr = start;
	*new_node = get_details();
	if(start == NULL){
		start = new_node;
		start->next = NULL;
		return start;
	}
	while(ptr->next != NULL){
		ptr = ptr->next;
 	}
	ptr->next = new_node;
	new_node->next=NULL;
	printf("The node has been added at the end.\n");

	return start;
}

struct node *display(struct node *start){
	int i = 1;
	if(start == NULL){
		printf("\nThe linked list is empty.\n\n");
		return start;
	}
	struct node *ptr;
	ptr = start;
	printf("\nThe linked list is displayed below: \n\n");
	while(ptr != NULL){
		printf("The details for node number %d is given below: \n", i);
		printf("Name: %s\n", ptr->name);
		printf("Register Number : %s\n\n", ptr->regno);
		i++;
		ptr = ptr->next;
	}
	printf("\n");
	return start;

}

struct node *add_head(struct node *start){
	struct node *new_node, *temp;
	temp = start;
	new_node = (struct node *) (malloc(sizeof(struct node)));
	*new_node = get_details();
	if(start == NULL){
		start = new_node;
		start->next = NULL;
	}

	else{
		new_node->next = temp;
		start = new_node;
	}
	printf("The data has been added to the head of the linked list.\n");
	return start;

}

struct node *delete_head(struct node *start){
	struct node *temp1, *temp2;
	temp2 = start;
	if(start == NULL){
		printf("The linked list is empty.\n\n");
		return start;
	}
	temp1 = start->next;
	free(temp2);
	start = temp1;
	printf("The first node has been deleted sucessfully.\n");
	return start;
}

struct node *delete_end(struct node *start){
	if(start == NULL){
		printf("The linked list is empty.\n\n");
		return start;
	}
	if(start->next == NULL){
		printf("Currenlty, there is only one node in the linked list so, the first node is also the last node.\n");
		start = delete_head(start);
		return start;
	}
	struct node *ptr, *temp;
	ptr = start;
	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	temp = ptr;
	ptr = start;
	while(ptr->next != temp){
		ptr = ptr->next;
	}
	ptr->next = NULL;
	free(temp);
	printf("The last node has been deleted sucessfully.\n");
	return start;

}

struct node *add_in_middle(struct node *start){
	if(start == NULL){
		printf("The linked list is empty. Add some nodes first.\n\n");
		return start;
	}
	if(start->next == NULL){
		printf("The linked list has only one node so a new node can't be added at the middle.");
		return start;
	}
	struct node *ptr, *new_node;
	new_node = (struct node *) (malloc(sizeof(struct node)));
	int count = 0, middle;
	ptr = start;
	*new_node = get_details();
	while(ptr != NULL){
		ptr = ptr->next;
		count += 1;
	}
	if(count % 2 == 0){
		middle = (count/2)-1;
	}
	else{
		middle = ((count-1)/2);
	}
	ptr = start;
	for(int i = 0; i<middle; i++){
		ptr = ptr->next;
	}
	if(start->next == NULL){
		start->next = new_node;
		new_node->next = NULL;
		return start;
	}
	new_node->next = ptr->next;
	ptr->next = new_node;
	return start;
}

struct node *delete_the_middle(struct node *start){
	if(start == NULL){
		printf("The linked list is empty. Add some nodes first.\n\n");
		return start;
	}
	if(start->next == NULL){
		printf("The linked list has only 1 node so it's middle node can't be deleted.\n");
		return start;
	}
	struct node *ptr, *succedptr, *mid_node;
	int count = 0, middle;
	ptr = start;
	while(ptr != NULL){
		ptr = ptr->next;
		count += 1;
	}
	if(count % 2 == 0){
		middle = (count/2);
	}
	else{
		middle = ((count-1)/2);
	}
	ptr = start;
	for(int i = 0; i<middle; i++){
		ptr = ptr->next;
	}
	mid_node = ptr;
	if(mid_node->next == NULL){
		ptr = start;
		while(ptr->next != mid_node){
			ptr = ptr->next;
		}
		ptr->next = NULL;
		free(mid_node);
		return start;
	}
	succedptr = ptr->next;
	ptr = start;
	while(ptr->next != mid_node){
		ptr = ptr->next;
	}
	ptr->next = succedptr;
	free(mid_node);
	printf("The middle node has been deleted successfully.\n");
	return start;
}

struct node get_details(){
	struct node temp;
	printf("Enter the name: ");
	scanf("%s", &temp.name);
	printf("Enter the registar number: ");
	scanf("%s", &temp.regno);
	
	return temp;
	
}



