#include <iostream>
using namespace std;



class date{
	private:
		int day;
		int month;
		int year;
		
	public:
		void get_details(){
			cout<<"Enter the day: ";
			cin>>day;
			cout<<"Enter the month: ";
			cin>>month;
			cout<<"Enter the year: ";
			cin>>year;
			
		}
		class date operator -(class date obj){
			class date temp;
			temp.year = year - obj.year;
			temp.month = month - obj.month;
			if(temp.month <0){
				temp.month = temp.month + 12;
				temp.year = temp.year - 1;
			}
			temp.day = day - obj.day;
			if(temp.day<0){
				temp.day = temp.day + 30;
				temp.month = temp.month - 1;
			}

			return temp;
}
		void display(){
			cout<<"Year: "<<year<<endl;
			cout<<"Month: "<<month<<endl;
			cout<<"Day: "<<day<<endl;
		}



	
};




int main(){
	class date purchase, current, a;
	cout<<"Enter the purchase date: "<<endl;
	purchase.get_details();
	
	cout<<endl<<endl;
	
	cout<<"Enter the current date: "<<endl;
	current.get_details();
	
	a = current - purchase;
	cout<<"The age is given below."<<endl;
	a.display();
	
	
	return 0;
}


