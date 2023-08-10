#include <iostream>
#include <malloc.h>
using namespace std;

class matrix{
	private:
		int row;
		int col;
		int *array;

	public:
		matrix(){
			row = 2;
			col = 2;
		}
		matix(int x){
			row = x;
			col = x;
		}
		matrix(int x, int y){
			row = x;
			col = y;
		}
		matrix(const matirx &m){
			row = m.row;
			col = m.col;
		}
		
		int *create_matrix(){
			array = new array[row][col];
		}
	
};
