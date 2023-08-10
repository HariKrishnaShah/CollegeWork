#include <stdio.h>

int main(){
	int A[10][10], B[10][10], ar,ac,br,bc, M[10][10], sum = 0;
	
	printf("Enter the number of rows and columns of first matrix: ");
	scanf("%d%d", &ar, &ac);
	printf("\nEnter the number of rows and columns of second matrix: ");
	scanf("%d%d", &br, &bc);
	
	if(ac!=br){
		printf("The matrix multiplication is not possible.");
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
	
	for(int a = 0; a<ar; a++){
		for(int b = 0; b<bc; b++){
			for(int c = 0; c<ac; c++){
				sum = sum + A[a][c]*B[c][b];
			}
			M[a][b] = sum;
			sum = 0;
		}
	}
	
	printf("\nThe product of the matrices is: \n");
	for(int i = 0; i<ar; i++){
		for(int j = 0; j<bc; j++){
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
}
		
	return 0;
}
