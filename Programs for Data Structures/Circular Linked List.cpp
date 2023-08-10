#include <stdio.h>
#include <malloc.h>

struct node{
		int data;
		struct node *next;
	};

struct node *create_and_expand(struct node *);
struct node *insert_end(struct node *);
struct node *display(struct node *);
struct node *count(struct node *);
struct node *search(struct node *);
struct node *add_head(struct node *);
struct node *add_after(struct node *);
struct node *add_before(struct node *);
struct node *delete_head(struct node *);
struct node *delete_end(struct node *);
struct node *delete_with_data(struct node *);
struct node *delete_before_data(struct node *);
struct node *delete_after_data(struct node *);
struct node *delete_all(struct node *start);
int main(){
	int option = 0;
	struct node *start = NULL;

	while(option != -1){
		printf("\t\t\tThis program is created by Hari Krishna Shah.\n");
		printf("Welcome to the Main-Menu !\n\
		Enter 1 to create and expand linked list \n\
		Enter 2 to add node after end.\n\
		Enter 3 to display linked list.\n\
		Enter 4 to count the number of nodes in the linked list.\n\
		Enter 5 to search the linked list\n \
		Enter 6 to add node in the beginning\n \
		Enter 7 to add node after data\n \
		Enter 8 to add node before data\n \
		Enter 9 to delete the first node\n \
		Enter 10 to delete the last node\n \
		Enter 11 to delete the node with the searched data\n \
		Enter 12 to delete the node which is before the searched data.\n \
		Enter 13 to delete the node which is after the searched data\n \
		Enter 14 to delete the list\n \
		Enter -1 to quit the program.\n");
		printf("\nEnter an option:");
		scanf("%d", &option);

		switch(option){

			case 1:
				start = create_and_expand(start);
				break;

			case 2:
				start = insert_end(start);
				break;

			case 3:
				start = display(start);
				break;

			case 4:
				start = count(start);
				break;
			case 5:
				start = search(start);
				break;
			case 6:
				start = add_head(start);
				break;
			case 7:
				start = add_after(start);
				break;
			case 8:
				start = add_before(start);
				break;
			case 9:
				start = delete_head(start);
				break;
			case 10:
				start = delete_end(start);
				break;
			case 11:
				start = delete_with_data(start);
				break;
			case 12:
				start = delete_before_data(start);
				break;
			case 13:
				start = delete_after_data(start);
				break;
			case 14:
				start = delete_all(start);
			case -1:
				break;
			default:
				printf("Please enter a valid option and try again !!!\n\n");
		}

	}
	printf("Thank you for using the program.\n");
	printf("The program exited successfully.\n");
	return 0;
}

struct node *create_and_expand(struct node *start){
	struct node *new_node, *ptr, temp;
	int num;
	if(start == NULL){
		new_node = (struct node *) (malloc(sizeof(struct node)));
		start = new_node;

		printf("Enter the data to insert in the first node: ");
		scanf("%d", &num);
		start->data = num;
		start->next = start;
		printf("The linked list has been created.\n\n");
	}
	else{
		printf("The linked list already exists.\n");
	}
	printf("Enter the data below to expand the linked list.\n");
	ptr = start;
	while(ptr->next !=start){
			ptr = ptr->next;
	}
	printf("Enter -1 to stop expanding the list else enter the data to store in the next node: ");
		scanf("%d", &num);
	while(num !=-1){
		struct node *new_node;
		new_node = (struct node *) (malloc(sizeof(node)));
		ptr->next = new_node;
		new_node->next = start;
		new_node->data = num;
		ptr = new_node;
		printf("Enter -1 to stop expanding the list else enter the data to store in the next node: ");
		scanf("%d", &num);
	}
	printf("\n");
	return start;

}

struct node *insert_end(struct node *start){
	if(start == NULL){
		printf("The linked list is empty.\n");
		start = create_and_expand(start);
		return start;
	}
	int num;
	struct node *ptr, *new_node;
	new_node = (struct node *) (malloc(sizeof(struct node)));
	ptr = start;
	if(start == NULL){
		printf("The linked list is empty. Add some nodes first.\n\n");
		return start;
	}
	while(ptr->next != start){
		ptr = ptr->next;
 	}
	ptr->next = new_node;
	printf("Enter the data to store at the last node: ");
	scanf("%d", &num);
	new_node->data = num;
	new_node->next=start;
	printf("The node has been added at the end.\n\n");

	return start;
}

struct node *display(struct node *start){
	if(start == NULL){
		printf("The linked list is empty.\n\n");
		return start;
	}
	struct node *ptr;
	ptr = start;
	printf("The data are: ");
	do{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	while(ptr != start);
		
	printf("\n\n");
	return start;

}

struct node *count(struct node *start){
	struct node *ptr;
	ptr = start;
	int count = 0;
	if(start == NULL){
		printf("The linked list is empty.\n The number of nodes is 0.\n");
		return start;
	}
	do{
	count += 1;
		ptr = ptr->next;
	}
	while(ptr != start);
	printf("The number of nodes are %d.\n\n", count);

	return start;
}

struct node *search(struct node *start){
	if(start == NULL){
		printf("The linked list is empty.\nAdd some nodes first.\n");
	}
	struct node *ptr;
	ptr = start;
	int i = 0;
	int count = 0;
	int number;
	printf("Enter a number to check in the linked list: ");
	scanf("%d", &number);
	do{
	if(ptr->data == number){
			printf("The number %d is available in the linked list at index %d.\n\n", number, i);
			count = count + 1;
		}
		i = i+1;
		ptr = ptr->next;
	}
	while(ptr!= start);
	if(count == 0){
		printf("The number %d is not available in the linked list.\n\n", number);
	}

	return start;
}

struct node *add_head(struct node *start){
	struct node *new_node, *temp1, *temp2, *ptr;
	int num;
	temp1 = start;
	new_node = (struct node *) (malloc(sizeof(struct node)));
	printf("Enter the data to insert in the first node: ");
	scanf("%d", &num);
	if(start == NULL){
		start = new_node;
		start->data = num;
		start->next = start;
	}
	else{
		new_node->next = temp1;
		new_node->data = num;
		start = new_node;
		ptr = start;
		do{
			ptr = ptr->next;
		}
		while(ptr->next != temp1);
		ptr->next = start;
	}
	printf("The data has been added to the head of the linked list.\n\n");

	return start;

}

struct node *add_after(struct node *start){
	if(start == NULL){
		printf("The link is empty. Add some nodes to the list first.\n\n");
		return start;
	}
	struct node *new_node, *ptr, *temp;
	new_node = (struct node *) (malloc(sizeof(struct node)));
	int num, check_data;
	printf("Enter the data after which the node is to be added: ");
	scanf("%d", &check_data);
	ptr = start;
	while(ptr->data != check_data){
 	ptr = ptr->next;
		if(ptr == start){
		printf("The searched data couldn't be found. The process terminated.\n\n");
		return start;
		}
 }
	printf("Enter the data to be stored: ");
	scanf("%d", &num);
	temp = ptr->next;
	ptr->next = new_node;
	new_node->data = num;
	new_node->next = temp;
	printf("The node has been added after the data %d.\n\n", check_data);
	return start;
}

struct node *add_before(struct node *start){
	if(start == NULL){
		printf("The link is empty. Add some nodes to the list first.\n\n");
		return start;
	}
	struct node *new_node, *ptr, *temp;
	int num, check_data;
	printf("Enter the data before which node is to be added: ");
	scanf("%d", &check_data);
	ptr = start;
	if(start->data == check_data){
		printf("The matched data was found to be in the first node of data.\n");
		printf("Now we need to add a new head to our linked list.\n");
		start = add_head(start);
		return start;
	}
	while(ptr->data != check_data){
	ptr = ptr->next;
	if(ptr == start){
		printf("The searched data couldn't be found. The process terminated.\n\n");
		return start;
	}
	}
	new_node = (struct node *) (malloc(sizeof(struct node)));
	printf("Enter the data to be stored: ");
	scanf("%d", &num);
	temp = ptr;

	ptr = start;
	while(ptr->next != temp){
	ptr = ptr->next;
	}
	ptr->next = new_node;
	new_node->data = num;
	new_node->next = temp;


	printf("The node has been added before the data %d.\n\n", check_data);

	return start;

}

struct node *delete_head(struct node *start){
	struct node *temp1, *temp2, *ptr;
	temp2 = start;
	if(start == NULL){
		printf("The linked list is empty.\n\n");
		return start;
	}
	if(start->next == start){
		free(start);
		start = NULL;
		printf("The linked list consists only 1 element so the first node is also the last node.\n");
		printf("The first node has been deleted successfully.\n");
		return start;
	}
	temp1 = start->next;
	start = temp1;
	ptr = start;
	do{
		ptr = ptr->next;
	}
	while(ptr->next != temp2);
	ptr->next = start;
	printf("The first node has been deleted sucessfully.\n\n");
	free(temp2);
	return start;
}

struct node *delete_end(struct node *start){
	if(start == NULL){
		printf("The linked list is empty.\n\n");
		return start;
	}
	if(start->next == start){
		printf("Currenlty, there is only one node in the linked list so, the first node is also the last node.\n");
		start = delete_head(start);
		return start;
	}
	struct node *ptr, *temp;
	ptr = start;
	while(ptr->next != start){
		ptr = ptr->next;
	}
	temp = ptr;
	ptr = start;
	while(ptr->next != temp){
		ptr = ptr->next;
	}
	ptr->next = start;
	free(temp);
	printf("The last node has been deleted sucessfully.\n\n");
	return start;

}

struct node *delete_with_data(struct node *start){
	if(start == NULL){
		printf("The linked list is empty. Add some nodes first.\n");
		return start;
	}
	struct node *ptr, *temp1, *temp2;
	ptr = start;
	int num;
	printf("Enter the data of the node which you want to delete: ");
	scanf("%d", &num);
	if(start->data == num){
		printf("The searched data is in the first node.");
		start = delete_head(start);
		return start;
	}
	while(ptr->data != num){
		ptr = ptr->next;
		if(ptr == start){
			printf("The searched data was not found in the linked list.");
			return start;
		}
	}
	temp1 = ptr;
	temp2 = ptr->next;
	ptr = start;
	while(ptr->next != temp1){
		ptr = ptr->next;
	}
	ptr->next = temp2;
	free(temp1);
	printf("The node containing the number %d has been deleted successfully.\n\n", num);
	return start;
}

struct node *delete_before_data(struct node *start){
	if(start == NULL){
		printf("The linked list is empty.\n\n");
		return start;
	}
	struct node *ptr, *temp1, *temp2;
	int num;
	printf("Enter the data of whose before node is to be deleted: ");
	scanf("%d", &num);
	if(start->data == num){
		printf("The data is in the first node of the linked list.\nso, the last node of the linked list will be deleted.\n");
		start = delete_end(start);
		return start;
	}
	ptr = start;
	while(ptr->data != num){
		ptr = ptr->next;
		if(ptr == start){
			printf("The searched data is not in the list.\n\n");
			return start;
		}
	}
	temp1 = ptr;
	ptr = start;
	while(ptr->next != temp1){
		ptr = ptr->next;
	}
	temp2 = ptr;
	if(temp2 == start){
		start = delete_head(start);
		return start;
	}
	ptr = start;
	while(ptr->next != temp2){
		ptr = ptr->next;
	}
	ptr->next = temp1;
	free(temp2);
	printf("The node before the number %d has been deleted.\n\n", num);
	return start;
}

struct node *delete_after_data(struct node *start){
	if(start == NULL){
		printf("The linked list is empty.\n\n");
		return start;
	}
	struct node *ptr, *temp1, *temp2;
	int num;
	printf("Enter the data of which suceeding node is to be deleted: ");
	scanf("%d", &num);
	ptr = start;
	while(ptr->data != num){
		ptr = ptr->next;
		if(ptr == start){
			printf("The searched data was not found in the list.\n The operation aborted.");
			return start;
		}
	}
	if(ptr->next == start){
		printf("The matched data is in the last node so the first node will be deleted.\n");
		start = delete_head(start);
		return start;
	}
	temp1 = ptr;
	temp2 = temp1->next;
	ptr = temp2->next;
	temp1->next = ptr;
	free(temp2);
	printf("The node after the data %d has been deleted.\n\n", num);
	return start;

}
struct node *delete_all(struct node *start){
	if(start == NULL){
		printf("The linked list is empty.\n Add some nodes first.\n");
		return start;
	}
	struct node *ptr;
	ptr = start;
	while(ptr->next != start){
		start = delete_end(start);
	}
	free(start);
	printf("The entire linked list has been deleted.\n");
	start = NULL;
	return start;
}








