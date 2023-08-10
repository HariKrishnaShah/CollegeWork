#include <stdio.h>

void sort(int array[50], int n){
	int temp;
	for(int i = 0; i<n; ++i){
		for(int j = i +1; j<n; ++j){
			if(array[j]>array[i]){
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}
	
}
int main(){
	int array[50];
	int n;
	printf("Please enter the number of elements to put into the array: ");
	scanf("%d", &n);
	printf("Enter the elements: ");
	
	for(int i =0; i<n; ++i){
		scanf("%d", &array[i]);
	}
	sort(array, n);
	printf("\nThe sorted array is: ");
	for(int i = 0; i<n; ++i){
		printf("%d ", array[i]);
	}
	return 0;
}
