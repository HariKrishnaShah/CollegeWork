#include <stdio.h>
#include <conio.h>
//coded by Hari Krishna Shah


int main(){
	int num, temp, total = 0, numc;
	printf("Enter a number: ");
	scanf("%d", &num);
	numc = num;
	
	while(numc!=0){
		temp = numc%10;
		total = total + temp;
		numc = numc/10;
	}
	
	printf("The sum of the number %d is %d.", num, total);
	return 0;
}

