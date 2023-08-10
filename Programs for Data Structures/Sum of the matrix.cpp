#include <stdio.h>


int main(){
	int matrix[50][50], row, col, sum = 0;
	
	printf("Enter the number of rows: ");
	scanf("%d", &row);
	printf("Enter the number of columns: ");
	scanf("%d", &col);
	printf("Enter the elements: ");
	for(int i = 0; i<row; i++){
		for(int j = 0; j<col; j++){
			scanf("%d", &matrix[i][j]);
		}
	}	
	
	for(int i = 0; i<row; i++){
		for(int j = 0; j<col; j++){
			sum += matrix[i][j];
	}
	}
	
	printf("The sum of the elements of the given matrix is %d.", sum);
	
	return 0;

}
