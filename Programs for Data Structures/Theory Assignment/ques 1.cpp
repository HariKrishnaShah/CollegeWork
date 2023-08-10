#include <stdio.h>
#include <malloc.h>
//Coded by Hari Krishna Shah
int second_max(int *array_head, int size);
int main(){
	int *array, n, max2;
	printf("Enter the number of elements to be inserted into the array: ");
	scanf("%d", &n);
	array = (int *) (malloc(n*sizeof(int)));
	
	printf("Enter the array elements: ");
	for(int i = 0; i<n; i++){
		scanf("%d", &array[i]);
	}
	
	max2 = second_max(array, n);
	printf("The second largest number is %d.", max2);
	
}
int second_max(int *array_head, int size){
	int *ptr, max, second_max;
	ptr = array_head;
	max = *array_head;
	for(int i = 0; i<size; i++){
		if(max<*ptr){
			max = *ptr;
		}
		ptr += 1;
	}
	ptr = array_head;
	
	if(*array_head != max){
		second_max = *array_head;
	}
	else{
		second_max = *(array_head+1);
	}
	for(int i = 0; i<size; i++ ){
		if(second_max<*ptr && *ptr != max){
			second_max = *ptr;
		}
		ptr = ptr + 1;
	}
	return second_max;
}
