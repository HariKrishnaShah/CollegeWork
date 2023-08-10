#include <stdio.h>
#include <malloc.h>


int main(){
	int *y;
	y = (int *) (malloc(sizeof(int)));
	*y = 50;
	printf("Before free() function call.\n\n");
	printf("The y is pointing at %d.\n\n", y);
	printf("The value pointed by y is %d.\n\n", *y);
	
	free(y);
	printf("After free() function call.\n\n");
	printf("The y is pointing at %d.\n\n", y);
	printf("The value pointed by y is %d.\n\n", *y);
	
	
	return 0;
}
