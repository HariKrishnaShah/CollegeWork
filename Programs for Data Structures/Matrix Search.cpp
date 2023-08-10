#include <stdio.h>


int main(){
	int matrix[50][50], row, col, search, count = 0;
	
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
	
	printf("Enter the number to search in the matrix: ");
	scanf("%d", &search);
	
	
	for(int i = 0; i<row; i++){
		for(int j = 0; j<col; j++){
			if(matrix[i][j]==search){
				printf("The number %d is present in the matrix at index (%d,%d).\n", search, i, j);
				count += 1;
			}
		}
	}
	
	if(count==0){
		printf("The number %d is not present in the given matrix.");
	}
	
	
	
	
	return 0;
}
