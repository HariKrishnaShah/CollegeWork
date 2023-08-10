#include <iostream>
#include <malloc.h>
using namespace std;

class vector{
	private:
		int *array;
		int size;
	public:
		vector(){
			// Dynamic Default constructor to the allocate 20 size to the newly formed array.
			array = (int *) (malloc(20*sizeof(int)));
		}
		void get_details();
		void display();
		class vector operator = (class vector &temp){
			size = temp.size;
			for(int i = 0; i<temp.size; i++){
				array[i] = temp.array[i];
			}
			
		}
};

void vector::get_details(){
	cout<<"Enter the size of the array: ";
	cin>>size;
	cout<<"Enter the array elements: ";
	for(int i = 0; i<size; i++){
		cin>>array[i];
	}
	cout<<endl;
}

void vector::display(){
	cout<<"The array elements are given: ";
	for(int i = 0; i<size; i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
}



int main(){
	class vector arrayA, arrayB;
	
	arrayA.get_details();
	cout<<"The original vector is given below: "<<endl;
	arrayA.display();
	
	arrayB = arrayA;
	
	cout<<"The copied vector is given below: "<<endl;
	arrayB.display();
	return 0;
}



