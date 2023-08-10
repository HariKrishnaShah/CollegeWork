#include <stdio.h>


int main(){
	int array[100], size;
	printf("Enter the size of array: ");
	scanf("%d", &size);
	
	printf("Enter the elements of the array: ");
	for(int i = 0; i<size; i++){
		scanf("%d", &array[i]);
	}
	
	printf("The elements of the array are given below: ");
	for(int i = 0; i<size; i++){
		printf("\n %d", array[i]);
	}
	return 0;
}
