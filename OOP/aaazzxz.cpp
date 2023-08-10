#include <iostream>
using namespace std;


class details{
	private:
		char name[200];
		int id;
		
	public:
		void get_details(){
			cout<<"Enter the name: ";
			cin>>name;
			cout<<"Enter the id: ";
			cin>>id;
		}
		
		void print_details(){
			cout<<"Name: "<<name<<endl;
			cout<<"Id: "<<id<<endl;
		}
	
	
};


int main(){
	class details d;
	d.get_details();
	d.print_details();
	
	return 0;
}

