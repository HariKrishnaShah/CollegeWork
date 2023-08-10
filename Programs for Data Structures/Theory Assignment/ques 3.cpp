#include <stdio.h>
#include <malloc.h>
//Coded by Hari Krishna Shah

int main(){
	int size, *array, check;
	printf("Enter the number of elements to be stored in the array: ");
	scanf("%d", &size);
	array = (int *) (malloc(size*sizeof(int)));
	printf("Enter the array elements: ");
	for(int i = 0; i<size; i++){
		scanf("%d", &array[i]);
	}
	
	for(int i = 0; i<size; i++){
		for(int j = i+1; j<size; j++){
			if(array[i]+ array[j] == 50){
				printf("The number %d and %d which is at index %d and %d make a pair of exact 50.\n", array[i], array[j], i, j);
				check = 1;
			}
		}
	}
	
	if(check == 0){
		printf("The are no paris of elements in the array whose sum is 50.\n");
	}
	return 0;
}
