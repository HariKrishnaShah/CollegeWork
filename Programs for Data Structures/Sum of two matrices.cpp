#include <stdio.h>

int main(){
	int A[10][10], B[10][10], ar,ac,br,bc, M[10][10], sum = 0;
	
	printf("Enter the number of rows and columns of first matrix: ");
	scanf("%d%d", &ar, &ac);
	printf("\nEnter the number of rows and columns of second matrix: ");
	scanf("%d%d", &br, &bc);
	
	if(!(ar==br && ac == bc)){
		printf("The matrix sum is not possible.");
	}
	else{
	printf("\nEnter the matrix elements for the first matrix: ");
	for(int i = 0; i<ar; i++){
		for(int j = 0; j<ac; j++){
			scanf("%d", &A[i][j]);
		}
	}
	printf("Enter the matrix elements for the second matrix: ");
	for(int i = 0; i<br; i++){
		for(int j = 0; j<bc; j++){
			scanf("%d", &B[i][j]);
		}
	}
	for(int i = 0; i<ar; i++){
		for(int j = 0; j<ac; j++){
			sum = A[i][j] + B[i][j];
			M[i][j] = sum;
		}
	}	
	printf("The Sum of the matrix is : \n");
	for(int i = 0; i<ar; i++){
		for(int j = 0; j<ac; j++){
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
}		
	return 0;
}
