#include <stdio.h>
//Coded By Hari Krishna Shah

int add(int n){
	if (n == 0)
       return 0;
	return(n + add(n-1));
}

int main(){
	int num, total;
	printf("Enter a number: ");
	scanf("%d", &num);
	total = add(num);
	printf("The sum of the first %d natural numbers is %d", num, total);
	return 0;
}
