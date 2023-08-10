#include <stdio.h>
#include <malloc.h>
//Coded by Hari Krishna Shah

int main(){
	printf("\t\t\t*****Welcome to the Binary Search. This program is made by Hari Krishna Shah *****\n");
	int *array, size, temp, search, mid, start, end, flag,search_count, exit = 0;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	array = (int *) (malloc(size*sizeof(int)));
	printf("Enter the elements of the array: ");
	for(int i = 0; i<size; i++){
		scanf("%d", &array[i]);
	}
	
	for(int i = 0; i<size; i++){
		for(int j = i+1; j<size; j++){
			if(array[j]<array[i]){
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	printf("The sorted array is : ");
	for(int i = 0; i<size; i++){
		printf("%d  ", array[i]);
	}
	
	while(exit == 0){
		start = 0;
		end = size - 1;
		flag = 0;
		search_count = 0;
		printf("\nEnter the number to search in the array: ");
	scanf("%d", &search);

	while(start<=end){
		mid = (start+end)/2;
		if(search == array[mid]){
			flag = 1;
			printf("The searched data is found in the array at position %d.", mid);
			break;
		}
		if(search>array[mid]){
			start = mid + 1;
		}
		else{
			end = mid - 1;
		}
		search_count += 1;
	}
	printf("\nThe total search count is %d.", search_count);
	if(flag == 0){
		printf("\nThe number was not found in the array.");
	}
	printf("\nEnter 1 to exit or 0 to run the search again: ");
	scanf("%d", &exit);
	printf("\n\n");
	
	}
	free(array);
	

	return 0;
}
