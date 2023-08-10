#include <iostream>
#include <malloc.h>
using namespace std;

class date{
	private:
		int day;
		int month;
		int year;
		
	public:
		void get_detail(){
			cout<<"Enter the day: ";
			cin>>day;
			cout<<"Enter the month: ";
			cin>>month;
			cout<<"Enter the year: ";
			cin>>year;
			cout<<endl;
		}
		
		void display(){
			cout<<"Day: "<<day<<endl;
			cout<<"Month: "<<month<<endl;
			cout<<"Year: "<<year<<endl;
		}
		//Default Constructor
		date(){
			day = 4;
			month = 2;
			year = 1999;
		}
		//Parameterized Constructor
		date(int a, int b, int c){
			day = a;
			month = b;
			year = c;
		}
		//Copy constructor
		date(class date &obj){
			day = obj.day;
			month = obj.month;
			year = obj.year;
		}
		friend void print(class date &obj);
		friend class new_date;
		

};

//friend function
void print(class date &obj){
			cout<<"Day: "<<obj.day<<endl;
			cout<<"Month: "<<obj.month<<endl;
			cout<<"Year: "<<obj.year<<endl;
	
}

class new_date{
	private:
		int day;
		int month;
		int year;
		
	public:
		void copy_from_date_class(class date &obj){
			day = obj.day;
			month = obj.month;
			year = obj.year;
		}
		
		void display(){
				cout<<"Day: "<<day<<endl;
				cout<<"Month: "<<month<<endl;
				cout<<"Year: "<<year<<endl;
			}
};
int main(){
	class date d;
	d.get_detail();
	d.display();
	cout<<endl<<endl;
	class date o;
	o.display();
	
	cout<<endl<<endl;
	class date p(12, 12, 1212);
	
	cout<<endl;
	p.display();
	
	cout<<endl;
	class date u(d);
	u.display();
	
	print(d);
	
	cout<<endl<<endl;
	class new_date n;
	n.copy_from_date_class(d);
	n.display();
	return 0;
}

