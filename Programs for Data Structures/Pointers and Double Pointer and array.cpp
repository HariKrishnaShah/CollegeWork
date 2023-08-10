#include <stdio.h>

int main(){
	int arr[100];
	int *ptr, **pptr;
	
	
	printf("Enter the elements of the array: ");
	for(int i = 0; i<10; i++){
		scanf("%d", &arr[i]);
	}
	
	printf("The elements of the array are: ");
	for(int i = 0; i<10; i++){
		printf("%d ", arr[i]);	
	}
	
	
	ptr = &arr[5];
	
	*ptr = 15;
	printf("\nThe modified value of arr[5] is %d.", arr[5]);
	
	ptr = ptr + 2;
	*ptr = 20;
	printf("\nThe modified value of arr[7] is %d.", arr[7]);
	
	pptr = &ptr;
	**pptr = 99;
	printf("\nThe modified value of arr[7] is %d.", arr[7]);
	
	printf("\nThe elements of the array after modification are: ");
	for(int i = 0; i<10; i++){
		printf("%d ", arr[i]);	
	}
	
	return 0;
}
