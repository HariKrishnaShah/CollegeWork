#include <iostream>
using namespace std;

class client_details{
	protected:
		char name[100];
		// 1 for citizenship, 2 for driving license, 3 for passport_id;
		int national_id_type;
		union national_id{
			long long int citizenship;
			long long int driving_license;
			long long int passport_id;
		}id;
		struct date_of_birth{
			int day;
			int month;
			int year;
		}dob;
		struct address{
			char city[100];
			char country[100];
		}location;

	public:
		void get();
		void display();
};

class saving_account:public client_details{
	protected:
		float acc_no;
		float amount;
	public:
		saving_account(){
			amount = 0;
		}
		void get();
		void display();
		void withdraw();
		void deposit();
};

class current_account:public client_details{
	protected:
		float amount;
		float acc_no;
	public:
		current_amount(){
			amount = 0;
		}
		void get();
		void display();
		void withdraw();
		void deposit();
};

class asset: public client_details{
	protected:
		char asset_name[100];
		float amount;
	public:
		asset(){
			amount = 0;
		}
		void get();
		void display();
};

class Bank:public saving_account, virtual public current_account, virtual public asset{
	protected:
		float loan_amount;
		float total_balance;
		float net_balance;
	public:
		void get();
		void display();
		void calculate_optimal_loan();
		void loan();
		void calculate_interest_amount();
};

