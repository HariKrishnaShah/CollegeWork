#include <iostream>
#include <malloc.h>
using namespace std;

class Address{
	protected:
		char city[100];
		char district[100];
		char country[100];

	public:
		void get();
		void display();
	
};

class saving_account{
	protected:
		float amount;
		float acc_no;
	public:
		void get();
		void display();
		void withdraw();
		void deposit();
};

class current_account{
	protected:
		float amount;
		float acc_no;
	public:
	void get();
	void display();
	void withdraw();
	void deposit();
};

class asset{
	protected:
		char asset_name[100];
		float amount;
	public:
	void get();
	void display();
};
class Bank: public Address, public saving_account, public current_account, public asset{
	protected:
		char name[100];
		long long int national_id;
		struct Day_of_Birth{
			int year;
			int month;
			int day;
		}dob;
	public:
	void get();
	void display();
	void calculate_optimal_loan();
	void give_loan();
	void calculate_interest_amount;
};

