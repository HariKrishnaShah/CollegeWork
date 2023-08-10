#include <stdio.h>


int main(){
	int array[100], size, search, count;
	printf("Enter the size of array: ");
	scanf("%d", &size);
	
	printf("Enter the elements of the array: ");
	for(int i = 0; i<size; i++){
		scanf("%d", &array[i]);
	}
	
	printf("Enter the number to search in the array: ");
	scanf("%d", &search);
	for(int i = 0; i<size; i++){
		if(array[i]==search){
			count += 1;
			if(count==1){
				printf("The number %d is available at index: ");
			}
			printf("\n\t\t%d. %d", count, i);
		}
	}
	
	if(count ==0){
		printf("The number %d is not available in the array.", search);
	}
	
	
	
	return 0;
}
