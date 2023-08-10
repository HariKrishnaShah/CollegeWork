#include <iostream>
#include <malloc.h>
using namespace std;

class renewal{
	public:
		int renewal_count;
		struct renewal_date{
			int year;
			int month;
			int day;
		}*rd;
		int price;
		int renewal_gap;

		renewal(){
			rd = NULL;
		}

		~renewal(){
			delete rd;
		}
	private:
		void get_details(int r_renewal_count, int r_price, int r_year, int r_month, int r_day, int r_renewal_gap){
			renewal_count = r_renewal_count;
		price = r_price;
		renewal_gap = r_renewal_gap;

		rd = (struct renewal_date *) (malloc(renewal_count*sizeof(struct renewal_date)));
		rd[0].year = r_year;
		rd[0].month = r_month;
		rd[0].day = r_day;

		for(int i = 1; i<renewal_count; i++){
			rd[i].day = rd[i-1].day + r_renewal_gap;

			if(rd[i].day>30){
				rd[i].day = rd[i].day - 30;
				rd[i].month = rd[i].month + 1;
			}
			if(rd[i].month>12){
				rd[i].month = rd[i].month - 12;
				rd[i].year = rd[i].year + 1;
			}
	}
		}
	public:
		void display(){
				int total_price = 1;
	cout<<"\nThe entered gap day for renewal is "<<renewal_gap<<"."<<endl;
	cout<<"The entered price for each renewal is "<<price<<"."<<endl;
	cout<<"Following is the list of each renewal date."<<endl<<endl;

	for(int i = 0; i<renewal_count; i++){
		cout<<"Below is detail for renewal date number "<<i+1<<endl;
		cout<<"Year: "<<rd[i].year<<endl;
		cout<<"Month: "<<rd[i].month<<endl;
		cout<<"Day: "<<rd[i].day<<endl<<endl;
	}
	total_price = total_price*renewal_count;
	cout<<"The total price for the renewal is "<<total_price<<"."<<endl;
		}

};


int main(){
	class renewal r;
	int r_count, r_price, r_year, r_month, r_day, r_renewal_gap, r_renewal_count;

	cout<<"Enter the how many times you want to renew the sim card: ";
	cin>>r_renewal_count;
	cout<<"Enter the day after which sim is to be renewed: ";
	cin>>r_renewal_gap;

	cout<<"Enter the price of each renewal: ";
	cin>>r_price;
	cout<<"Enter the current year of renewal: ";
	cin>>r_year;
	cout<<"Enter the current month of renewal: ";
	cin>>r_month;
	cout<<"Enter the current day of renewal: ";
	cin>>r_day;

	r.get_details(r_renewal_count, r_price, r_year, r_month, r_day, r_renewal_gap);

	for(int i = 0; i<r_renewal_count; i++){
		r.display();
	}

	return 0;


}
