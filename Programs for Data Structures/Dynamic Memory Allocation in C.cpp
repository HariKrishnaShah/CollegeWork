#include <stdio.h>
#include <malloc.h>

int main() {
	int *array, arr_size;
	printf("Enter the number of elements to be stored in the array: ");
	scanf("%d", &arr_size);
	array = (int *) (malloc(arr_size*sizeof(int)));
	printf("Enter the elements of the array: ");
	for(int i = 0; i<arr_size; i ++) {
		scanf("%d", &array[i]);
	}
	printf("The elements of the array are: ");
	for(int i = 0; i<arr_size; i ++) {
		printf("%d ", array[i]);
	}
	
	free(array);



	return 0;
}

