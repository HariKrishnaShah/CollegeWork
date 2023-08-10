#include <stdio.h>

struct student{
	int x;
	struct student *l;
};

int main(){
	int z;
	int *j;
	printf("The size of pointer variable j is %d.", sizeof(j));
	z = sizeof(struct student);
	printf("\nThe value of z is %d.", z);
	
	return 0;
}
