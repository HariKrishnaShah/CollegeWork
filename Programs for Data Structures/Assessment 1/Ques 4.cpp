//Hari Krishna Shah
//VIT ID: 21BCS0167

/* 4. Define a structure “complex” to read two complex numbers and perform addition,
subtraction of these two complex numbers and display the result(implement using pointers with
structures). */

#include <stdio.h>
#include <math.h>
int main(){
	struct complex
	{
	float real;
	float imaginary;
	};
		
	struct complex c1, c2;
	printf("Enter the real part of the first number: ");
	scanf("%f", &c1.real);
	printf("Enter the imaginary part of the first number: ");
	scanf("%f", &c1.imaginary);
	printf("The first complex number is %.2f + %.2fi.", c1.real, c1.imaginary);
	printf("\n\nEnter the real part of the second number: ");
	scanf("%f", &c2.real);
	printf("Enter the imaginary part of the second number: ");
	scanf("%f", &c2.imaginary);
	printf("The second complex number is %.2f + %.2fi.", c2.real, c2.imaginary);
	
	printf("\n\nThe sum of the two complex number is given by: \nSum = %.2f + %.2fi", c1.real + c2.real, c1.imaginary + c2. imaginary);	
	return 0;
}

