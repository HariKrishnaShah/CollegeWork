#include <iostream>
using namespace std;
//Coded by Hari Krishna Shah

int main(){
	int A[10][10], B[10][10], ar,ac,br,bc, M[10][10], sum = 0;
	
	cout<<"Enter the number of rows and columns of first matrix: "<<endl;
	cin>> ar>>ac;
	cout<<"Enter the number of rows and columns of second matrix: "<<endl;
	cin>>br>>bc;
	
	if(ac!=br){
		cout<<"The matrix multiplication is not possible."<<endl;;
	}
	
	else{
		
	
	
	cout<<"Enter the matrix elements for the first matrix: "<<endl;;
	for(int i = 0; i<ar; i++){
		for(int j = 0; j<ac; j++){
			cin>>A[i][j];
		}
	}
	
	
	
	cout<<"Enter the matrix elements for the second matrix: "<<endl;
	for(int i = 0; i<br; i++){
		for(int j = 0; j<bc; j++){
			cin>>B[i][j];
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
	
	cout<<"\nThe product of the matrices is: \n"<<endl;
	for(int i = 0; i<ar; i++){
		for(int j = 0; j<bc; j++){
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
}
		
	return 0;
}
