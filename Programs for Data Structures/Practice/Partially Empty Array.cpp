#include <stdio.h>

int main(){
	int arr[100];
	printf("Enter the elements of the array: ");
	
	for(int i = 0; i<10; i++){
		scanf("%d", &arr[i]);
	}
	
	printf("The elements of the array are: ");
	for(int i = 0; i<100; i++){
		printf("%d ", arr[i]);	
	}	
	
	return 0;
}
