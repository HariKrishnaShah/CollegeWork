//Hari Krishna Shah
//VIT ID: 21BCS0167
/*1.Write a program that declares and initializes an array of 10 elements, it is a (1-D) one
dimensional integer array named temperature. Use the following temperatures to initialize the
array: 78 89 65 90 35 20 88 101 56 99 Then, display the contents of the array on the screen and
calculate and display the mean (average) of the temperatures.*/


#include <stdio.h>

int main(){
	int temperature[10] = { 78, 89, 65,  90, 35, 20, 88, 101, 56, 99}, sum = 0, mean;
	printf("The entered temperature are: ");
	
	for(int i = 0; i<10; i++){
		printf("%d ", temperature[i]);
		sum += temperature[i];
		mean = sum/10;
	}
	printf(".");
	printf("\nThe mean temperature is %d.", mean);
	
	return 0;
}

