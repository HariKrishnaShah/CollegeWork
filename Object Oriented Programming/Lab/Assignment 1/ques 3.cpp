#include <iostream>
#include <cstring>
#include <string>
#include <malloc.h>
using namespace std;
//Coded by Hari Krishna Shah
class books{
	private:
		char title[50];
		char author[50];
		char publication[50];
		int year_pub;
		float price;
		int stock_position;
	public:
		books(){
			year_pub = 2022; // current year
			stock_position = 0; // until and unless specified
			strcpy(publication, "Shah_Library"); //default owner and publisher of the book
		}
		~books(){
			// objects are intialized to these data values if they go out of scope. It protects objects from data leak.
			strcpy(title, "XXXXX");
			strcpy(author, "XXXXX");
			strcpy(publication, "XXXXX");
			price = 0;
			price = 99999;
			stock_position = 99999;
		}
		void get_details();
		string return_title();
		void display();
		string return_author();
		int return_price();
		int request_handle(char book_title[50], char book_author[50], int required_copies);
		void display_message(int request, int required_copies);
		
};
void books::get_details(){
			cout<<"Enter the title of the book: ";
			cin>>title;
			cout<<"Enter the author of the book: ";
			cin>>author;
			cout<<"Enter the publisher of the book: ";
			cin>>publication;
			cout<<"Enter the year of publication of the book: ";
			cin>>year_pub;
			cout<<"Enter the price of the book: ";
			cin>>price;
			cout<<"Enter the number of copies: ";
			cin>>stock_position;
}
void books::display(){
	cout<<"Book Title: "<<title<<endl;
	cout<<"Author: "<<author<<endl;
	cout<<"Publisher: "<<publication<<endl;
	cout<<"Year of publication: "<<year_pub<<endl;
	cout<<"Price: "<<price<<endl;
	cout<<"Number of copies available: "<<stock_position<<endl<<endl;
}

string books::return_title(){
	return title;
}
string books::return_author(){
	return author;
}
int books::return_price(){
	return price;
}
int books::request_handle(char book_title[50], char book_author[50], int required_copies){
	if((strcmp(book_title, title)==0) && ((strcmp(book_author, author) ==0)) && stock_position >= required_copies){
		return 1;
	}
	else if((strcmp(book_title, title)==0) && ((strcmp(book_author, author) ==0))){
		return 2;
	}
}

void books::display_message(int request, int required_copies){
	if(request == 1){
		cout<<"\nThe book "<<title<<" by the author "<<author<<" is available with us."<<endl;
		cout<<"There are "<<stock_position<<" number of copies available."<<endl;
		cout<<"The price for the each copy of the book is "<<price<<" . So, total price for "<<required_copies<<" number of copies is Rs "<<price*required_copies<<". "<<endl;
	}
	else if(request == 2){
	cout<<"\nSorry, there are only " <<stock_position<<" number of copies of the book "<<title<<" by the author "<<author<<" available with us."<<endl;
	cout<<"Required number of copies not available.!!!"<<endl;
	cout<<"We are short by "<<required_copies -stock_position<<" number of copies."<<endl;
	}
}


int main(){
	class books *b;
	b = (class books *) (malloc(sizeof(class books)));
	static int book_count = 0;
	int temp1_count = 0, temp2_count = 0;
	int option;
	do{
		cout<<"\t\tThis program is made by Hari Krishna Shah !!!"<<endl;
		cout<<"Welcome to the main menu"<<endl;
		cout<<"Enter an option from the menu below\n \
		Enter 1 to add books to the database\n \
		Enter 2 to display all the books\n \
		Enter 3 to sort the book in ascending order\n \
		Enter 4 to search the book by author name\n \
		Enter 5 to display books whose price is below certain price\n \
		Enter 6 to process a book purchase request \n \
		Enter -1 to quit the program"<<endl;
		cout<<"Enter your option here: ";
		cin>>option;
		cout<<endl;
		switch(option){
			case -1: {
				break;
			}
			case 1:{
				cout<<"Enter the number of books you want to add: ";
				cin>>temp1_count;
				book_count += temp1_count;
				cout<<endl;
				for(; temp2_count<book_count; temp2_count++){
					cout<<"Enter the details for book number "<<temp2_count+1<<" :"<<endl;
					b = (class books *) (realloc(b, book_count*sizeof(class books)));
					b[temp2_count].get_details();
					cout<<endl;
				}
				break;
			}
			case 2:{
				if(book_count == 0){
					cout<<"The database is empty. Add some books first."<<endl;
					break;
				}
				for(int i = 0; i<book_count; i++){
					cout<<"Details for book number "<<i+1<<" is given below."<<endl;
					b[i].display();
					cout<<endl;
				}
				break;
			}
			case 3:{
				if(book_count == 0){
					cout<<"There's isn't any book in the database. Add some books to the database first."<<endl;
					break;
				}
				class books temp;
				for(int i = 0; i<book_count; i++){
					for(int j = i+1; j<book_count; j++){
						if((b[i].return_title().compare(b[j].return_title()))>0){
							temp = b[i];
							b[i] = b[j];
							b[j] = temp;
						}
					}
				}
				cout<<"The books have been sorted in ascending order according to book title successfully."<<endl;
				break;
			}

			case 4:{
				if(book_count == 0){
					cout<<"\nThere's isn't any book in the database. Add some books to the database first."<<endl;
					break;
				}
				char search[50];
				cout<<"Enter the author name to search in the database: ";
				cin>>search;
				int flag1 = 0;
				for(int i = 0; i<book_count; i++){
					if(b[i].return_author().compare(search)==0){
						if(flag1 == 0){
							cout<<"\nFollowing book is authored by "<<search<<"."<<endl;
						}
						cout<<"Book number: "<<flag1+1<<"."<<endl;
						b[i].display();
						cout<<endl;
						flag1 += 1;
					}
				}
				if(flag1 == 0){
					cout<<"There isn't any book authored by "<<search<<" in the database.\nTry again with another author name."<<endl;
				}
				else{
					cout<<"Total "<<flag1<<" numbers of books were found in the database."<<endl;
				}
				break;
			}
				
			case 5:
			{
				if(book_count == 0){
					cout<<"There's isn't any book in the database. Add some books to the database first."<<endl;
					break;
				}
				int price;
				cout<<"Enter the price to find books below that price: ";
				cin>>price;
				int flag = 0;
				for(int i = 0; i<book_count; i++){
					if(b[i].return_price()<price){
						cout<<"Match Found. Book number: "<<flag+1<<endl;
						b[i].display();
						flag += 1;
					}
				}
				if(flag == 0){
					cout<<"There isn't any book below Rs."<<price<<" in the database."<<endl;
				}
				break;
			}
			case 6:{
				if(book_count == 0){
					cout<<"There book database is empty. Add some books first."<<endl;
				}
				else{
					char book_title[50], book_author[50];
					int required_copies, flag = 0, result=0;
					cout<<"Enter the title of the book you want to purchase: ";
					cin>>book_title;
					cout<<"Enter the author of the book: ";
					cin>>book_author;
					cout<<"Enter the required number of copies: ";
					cin>>required_copies;
					for(int i = 0; i<book_count; i++){
						result = b[i].request_handle(book_title, book_author, required_copies);
						if(result == 1 || result == 2){
							b[i].display_message(result, required_copies);
							flag += 1;
							break;
						}
					}
					if(flag == 0){
						cout<<"\nSTOCK- NOT Available. YET TO COME."<<endl;
					}
			}
				break;
			}
			default:{
				cout<<"Enter a valid option and try again."<<endl;
				break;
			}
				
		}
		cout<<endl;
	}
	while(option != -1);
	cout<<"Thank you for using the program.\nPlease drop a feedback or a comment."<<endl;
	
	return 0;
}
