#include <iostream>
using namespace std;

#define max_account 100
#define min_balance 1000

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
		void get_details(){
			cout<<"Enter the client details below."<<endl;
			cout<<"Name: ";
			cin>>name;
			cout<<"Choose a national id type."<<endl;
			cout<<"Enter 1 for citizenship, 2 for driving license or 3 for passport: ";
			cin>>national_id_type;
			cout<<"Enter your national id: ";
			cin>>id.citizenship;
			cout<<"Enter your birth details in integer below."<<endl;
			cout<<"Day of Birth: ";
			cin>>dob.day;
			cout<<"Month of Birth: ";
			cin>>dob.month;
			cout<<"Year of Birth: ";
			cin>>dob.year;
			cout<<"Enter your address details below."<<endl;
			cout<<"Enter your city: ";
			cin>>location.city;
			cout<<"Enter your country: ";
			cin>>location.country;
		}
		void display(){
			cout<<"The client details are given below: "<<endl;
			cout<<"Name: "<<name<<endl;
			if(national_id_type==1){
				cout<<"Citizenship number: "<<id.citizenship<<endl;
			}
			else if(national_id_type==2){
				cout<<"Driving License number: "<<id.driving_license<<endl;
			}
			else if(national_id_type==3){
				cout<<"Passport number: "<<id.passport_id<<endl;
			}
			
			cout<<"Date of birth is: "<<dob.year<<"/"<<dob.month<<"/"<<dob.day<<endl;
			cout<<"Address is: "<<location.city<<", "<<location.country<<endl;
		}
};

class saving_account:public virtual client_details{
	protected:
		int acc_no;
		float balance;
		int pin;
	public:
		saving_account(){
			balance = 0;
		}
		void get(){
			cout<<"Enter saving account number: ";
			cin>>acc_no;
			cout<<"Enter a PIN for security: ";
			cin>>pin;
			cout<<"The saving account has been created successfully created.";
		}
		void display(){
			cout<<"\nThe saving account details is given below: "<<endl;
			cout<<"Account number: "<<acc_no<<endl;
			cout<<"Balance Amount: "<<balance<<endl;
		}
		int search(int search_acc, int pin_search){
			if(search_acc == acc_no && pin_search == pin){
				return 1;
			}
			return 0;
		}
		void withdraw(){
			float withdraw_req, after_balance;
			cout<<"Enter the amount to withdraw: ";
			cin>>withdraw_req;
			
			after_balance = balance - withdraw_req;
			if(after_balance >min_balance){
				balance = after_balance;
				cout<<"Withdrawl Sucessful."<<endl;
			}
			else{
				cout<<"You don't have sufficient balance."<<endl;
			}
		}
		void deposit(){
			float deposit_req;
			cout<<"Enter the amount to deposit: ";
			cin>>deposit_req;
			balance += deposit_req;
			cout<<"Amount Deposited Sucessfully."<<endl;
		}
		int return_saving_pin(){
			return pin;
		}
};

class current_account:public virtual client_details{
	protected:
		int acc_no;
		float balance;
		int pin;
	public:
		current_account(){
			balance = 0;
		}
		void get(){
			cout<<"Enter current account number: ";
			cin>>acc_no;
			cout<<"Enter a PIN for security: ";
			cin>>pin;
			cout<<"The current account has been created successfully created.";
		}
		void display(){
			cout<<"The current account details is given below: "<<endl;
			cout<<"Account number: "<<acc_no<<endl;
			cout<<"Balance Amount: "<<balance<<endl;
		}
		int search(int search_acc, int pin_search){
			if(search_acc == acc_no && pin_search == pin){
				return 1;
			}
			return 0;
		}
		void withdraw(){
			float withdraw_req, after_balance;
			cout<<"Enter the amount to withdraw: ";
			cin>>withdraw_req;

			after_balance = balance - withdraw_req;
			if(after_balance >min_balance){
				balance = after_balance;
				cout<<"Withdrawl Sucessful."<<endl;
			}
			else{
				cout<<"You don't have sufficient balance."<<endl;
			}
		}
		void deposit(){
			float deposit_req;
			cout<<"Enter the amount to deposit: ";
			cin>>deposit_req;
			balance += deposit_req;
			cout<<"Amount Deposited Sucessfully."<<endl;
		}
		int return_current_pin(){
			return pin;
		}
};

class asset: public virtual client_details{
	protected:
		char asset_name[100];
		float worth;
	public:
		asset(){
			 worth = 0;
		}
		void get(){
			cout<<"Enter the name of the asset: ";
			cin>>asset_name;
			cout<<"Enter the worth of the asset: ";
			cin>>worth;
		}
		void display(){
			cout<<"The details of the asset owned by the client is given below."<<endl;
			cout<<"Name of the asset: "<<asset_name<<endl;
			cout<<"Worth of the asset: "<<worth<<endl;
		}
};

class Bank: public saving_account, public current_account, public asset{
	protected:
		// 1 for saving account, 2 for current account, 3 for both saving and current account
		int account_type;
		float loan_amount;
		float total_balance;
		float net_balance;
		int master_pin;
	public:
		Bank(){
			loan_amount = 0;
			total_balance = 0;
			net_balance = 0;
		}
		void get(){
			cout<<"Enter your master key for the bank security: ";
			cin>>master_pin;
			cout<<"Please choose an option from the below menu.\n \
			Enter 1 to create a saving account\n \
			Enter 2 to create a current account\n \
			Enter 3 to create both saving and current account\n"<<endl;
			cout<<"Enter your option here: ";
			cin>>account_type;
			
			if(account_type == 1){
				saving_account::get();
			}
			else if(account_type == 2){
				current_account::get();
			}
			else if (account_type == 3){
				saving_account::get();
				cout<<endl<<endl;
				current_account::get();
			}
			else{
				cout<<"Please enter a valid option."<<endl;
			}
		}
		void display(){
			if(account_type == 1){
				saving_account::display();
			}
			else if(account_type == 2){
				current_account::display();
			}
			else if(account_type == 3){
				saving_account::display();
				cout<<endl;
				current_account::display();
			}
			asset::display();
			total_balance = saving_account::balance + current_account::balance;
			cout<<"Total Balance: "<<total_balance<<endl;
			cout<<"Loan Amount: "<<loan_amount<<endl;
			cout<<"Net Balance: "<<total_balance - loan_amount<<endl;
		}
		int search_master(int master_pin_search){
			if(master_pin_search == master_pin){
				return 1;
			}
			else{
				return 0;
			}
			
		}
		float calculate_optimal_loan(){
			float optimal_loan_amount;
			asset::get();
			float total_net_worth;
			total_net_worth = saving_account::balance + current_account::balance + asset::worth;
			optimal_loan_amount = 0.5*total_net_worth;
			return optimal_loan_amount;
			
		}
		void loan(){
			float loan_req;
			int credit_acc;
			cout<<"Enter the loan amount you want: "<<endl;
			cin>>loan_req;
			if(loan_req<calculate_optimal_loan()){
				cout<<"Enter 1 to credit the loan to your saving account, 2 to credit it to your current account: ";
				cin>>credit_acc;
				if(credit_acc == 1 &&(account_type == 1 || account_type == 3)){
					saving_account::balance += loan_amount;
					cout<<"Loan granted."<<endl;
					loan_amount = loan_req;
					saving_account::balance += loan_amount;
				}
				else if (credit_acc == 2 &&(account_type == 2 || account_type == 3)){
					current_account::balance += loan_amount;
					cout<<"Loan granted."<<endl;
					loan_amount = loan_req;
					current_account::balance += loan_amount;
				}
				else{
					cout<<"Please enter a valid account type."<<endl;
				}
			}
			else{
				cout<<"You can't take that much loan."<<endl;
				cout<<"Loan request rejected."<<endl;
			}
		}
		
		int return_account_type(){
			return account_type;
		}
};

int main(){
	static int user_count = -1;
	class Bank client[max_account];
	int option = -1;
	do{
		cout<<"\n\t\t***Welcome to the Shah Bank Corp**"<<endl;
		cout<<"Please choose an option from menu below: \n \
		Enter 1 to create a bank account\n \
		Enter 2 to check your account profile\n \
		Enter 3 to check your balance\n \
		Enter 4 to withdraw money\n \
		Enter 5 to deposit money\n \
		Enter 6 to calculate your loan credit capactiy\n \
		Enter 7 to take loan \n \
		Enter -1 to quit the program"<<endl;
		cout<<"Enter your option here: ";
		cin>>option;
		
		switch(option){
			case -1:{
				cout<<"\nThe program exited successfully.";
				break;
			}
			
			case 1:{
				user_count += 1;
				client[user_count].saving_account::client_details::get_details();
				client[user_count].get();
				break;
			}
			case 2 :{
				int master_search_pin, master_found, i;
				cout<<"Enter the master key for your account: ";
				cin>>master_search_pin;
				for(i = 0; i<=user_count; i++){
					master_found = client[i].search_master(master_search_pin);
					if(master_found == 1){
						cout<<"Account Found."<<endl;
						break;
					}
				}
				if(master_found == 1){
					client[i].saving_account::client_details::display();
					client[i].display();
				}
				else if(master_found == 0){
					cout<<"The searched account didn't match with any account."<<endl;
				}
				break;
			}
			case 3 :{
				int master_search_pin, master_found, i;
				cout<<"Enter the master key for your account: ";
				cin>>master_search_pin;
				for(i = 0; i<=user_count; i++){
					master_found = client[i].search_master(master_search_pin);
					if(master_found == 1){
						cout<<"Account Found."<<endl;
						break;
					}
				}
				if(master_found == 1){
					client[i].display();
				}
				else if(master_found == 0){
					cout<<"The searched account didn't match with any account."<<endl;
				}
				break;
			}
			case 4 :{
				int master_search_pin, master_found, i, withdrawl_acc_type, saving_pin, current_pin;
				cout<<"Enter the master key for your account: ";
				cin>>master_search_pin;
				for(i = 0; i<=user_count; i++){
					master_found = client[i].search_master(master_search_pin);
					if(master_found == 1){
						cout<<"Account Found."<<endl;
						break;
					}
				}
				if(master_found == 1){

					cout<<"Enter the account from where you want to withdraw money."<<endl;
					cout<<"Enter 1 to withdraw from saving account or 2 to withdraw from current account: ";
					cin>>withdrawl_acc_type;
					if(withdrawl_acc_type == client[i].return_account_type()  || client[i].return_account_type()==3){
						if(withdrawl_acc_type==1){
							cout<<"Enter your saving account PIN: ";
							cin>>saving_pin;
							if(saving_pin == client[i].saving_account::return_saving_pin()){
								client[i].saving_account::withdraw();
							}
							else{
								cout<<"Incorrect PIN. Withdraw Request Rejected."<<endl;
							}
							
						}
						else if(withdrawl_acc_type==2){
							cout<<"Enter your current account PIN: ";
							cin>>current_pin;
							if(current_pin == client[i].current_account::return_current_pin()){
								client[i].current_account::withdraw();
							}
							else{
								cout<<"Incorrect PIN. Withdraw Request Rejected."<<endl;
							}
						}
					}
					else{
						cout<<"You don't have such acccount with the bank."<<endl;
					}
				}
				else if(master_found == 0){
					cout<<"The searched account didn't match with any account."<<endl;
				}
				
				break;
			}
			
			case 5: {
				int master_search_pin, master_found, i, deposit_acc_type;
				cout<<"Enter the master key for your account: ";
				cin>>master_search_pin;
				for(i = 0; i<=user_count; i++){
					master_found = client[i].search_master(master_search_pin);
					if(master_found == 1){
						cout<<"Account Found."<<endl;
						break;
					}
				}
				if(master_found == 1){

					cout<<"Enter the account to where you want to deposit money."<<endl;
					cout<<"Enter 1 to deposit to saving account or 2 to deposit to current account: ";
					cin>>deposit_acc_type;
					if(deposit_acc_type == client[i].return_account_type() || client[i].return_account_type()==3 ){
						if(deposit_acc_type==1){
							client[i].saving_account::deposit();
						}
						else if(deposit_acc_type==2){
							client[i].current_account::deposit();
						}
					}
					else{
						cout<<"You don't have such acccount with the bank."<<endl;
					}
				}
				else if(master_found == 0){
					cout<<"The searched account didn't match with any account."<<endl;
				}
				
				break;
			}
			
			case 6: {
				float loan_capacity;
				int master_search_pin, master_found, i;
				cout<<"Enter the master key for your account: ";
				cin>>master_search_pin;
				for(i = 0; i<=user_count; i++){
					master_found = client[i].search_master(master_search_pin);
					if(master_found == 1){
						cout<<"Account Found."<<endl;
						break;
					}
				}
				loan_capacity = client[i].calculate_optimal_loan();
				cout<<"Your optimal loan credit capacity is "<<loan_capacity<<"."<<endl;
				
				break;
			}
			case 7: {
				int key;
				cout<<"You need to a bank account to take loan."<<endl;
				cout<<"Press -1 to go to main menu and create bank account or any other key to proceed: ";
				cin>>key;
				if(key == -1){
					cout<<"Taking you to main menu."<<endl;
					break;
				}
				else{
					float loan_capacity;
					int master_search_pin, master_found, i;
					cout<<"Enter the master key for your account: ";
					cin>>master_search_pin;
					for(i = 0; i<=user_count; i++){
						master_found = client[i].search_master(master_search_pin);
						if(master_found == 1){
							cout<<"Account Found."<<endl;
							break;
						}
					}
					if(master_found == 1){
						client[i].loan();
					}
					else{
						cout<<"Account not found. Try again."<<endl;
					}
				}
				
				break;
			}

			
			default:{
				cout<<"Please enter a valid option."<<endl;
				break;
			}
			cout<<endl;
		}
	}
	while(option != -1);
}

