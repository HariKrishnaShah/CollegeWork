#include <iostream>
using namespace std;
/*

.. / .-.. --- ...- . / -.-- --- ..- / -.-. .... .. - .-. .-

*/

class Book_Details{
	protected:
		char title[100];
		char author[100];
		int edition_year;
	public:
		void get(){
			cout<<"Enter the title of the book: ";
			cin>>title;
			cout<<"Enter the author: ";
			cin>>author;
			cout<<"Enter the edition year: ";
			cin>>edition_year;

		}
		void display(){
			cout<<endl<<endl;
			cout<<"The book details are given below."<<endl;
			cout<<"The title is "<<title<<"."<<endl;
			cout<<"The author is "<<author<<"."<<endl;
			cout<<"The edition year is "<<edition_year<<"."<<endl;
		}
};

class Book_Sale_without_CD: public Book_Details{
	protected:
		int sales_quantity;
		float price;
	public:
		void gets(){
			Book_Details::get();
			cout<<"Enter the price for book without CD: ";
			cin>>price;
			cout<<"Enter the sales_quantity for book without CD:";
			cin>>sales_quantity;
		}
		void display_class(){
			Book_Details::display();
			cout<<"The sales quantity for book without cd is "<<sales_quantity<<"."<<endl;
			cout<<"The price for each book without CD is "<<price<<"."<<endl;
		}


};
class Book_Sale_with_CD: public Book_Details{
	protected:
		int sale_quantity;
		float prices;
	public:
		void get(){
			cout<<"Enter the price for book with CD: ";
			cin>>prices;
			cout<<"Enter the sales_quantity for book with CD:";
			cin>>sale_quantity;
		}
		void display(){
			cout<<"The details for sales of book with CD is given below."<<endl;
			cout<<"The sales quantity is "<<sale_quantity<<"."<<endl;
			cout<<"The price for each book with CD is "<<prices<<"."<<endl;
		}

};

class Book_Overall:virtual public Book_Sale_without_CD, public Book_Sale_with_CD{
	protected:
		int total_sale_quantity;
		float total_sale_amount;
	public:
		void get_details(){
			Book_Sale_without_CD::gets();
			Book_Sale_with_CD::get();
		}

		void calculate_sale(){
			total_sale_quantity = Book_Sale_without_CD::sales_quantity + Book_Sale_with_CD::sale_quantity;
			total_sale_amount = (Book_Sale_without_CD::sales_quantity*Book_Sale_without_CD::price) + (Book_Sale_with_CD::sale_quantity*Book_Sale_with_CD::prices);
		}
		void display_details(){
			Book_Sale_without_CD::display_class();
			Book_Sale_with_CD::display();
			cout<<"The total sale quantity is "<<total_sale_quantity<<"."<<endl;
			cout<<"The total sale amount is "<<total_sale_amount<<"."<<endl;
		}

};

int main(){
	class Book_Overall b;
	b.get_details();
	b.calculate_sale();
	cout<<endl;
	b.display_details();
	return 0;
}
