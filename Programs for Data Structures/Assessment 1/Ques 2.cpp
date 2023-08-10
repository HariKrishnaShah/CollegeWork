//Hari Krishna Shah
//VIT ID: 21BCS0167

/*2.Write a program to store an input list of five numbers in an array named list and display the
largest element in the array using a function named get_max. The function get_max will use
the array and its size as input parameters and then returns the largest element in the array.*/

#include <stdio.h>
int get_max(int list[5], int size){
	int max = list[0];
	
	for(int i = 0; i<size; i++){
		if(max<list[i]){
			max = list[i];
		}
	}
	return max;
	
}
int main(){
	int list[5], size = 5;
	printf("Enter the five numbers to store in the list: ");
	
	for(int i = 0; i<size; i++){
		scanf("%d", &list[i]);
	}
	
	printf("The largest integer stored in the list is %d.", get_max(list, size));
	
	return 0;
}

