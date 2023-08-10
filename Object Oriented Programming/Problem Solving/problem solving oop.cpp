#include <iostream>
#include <malloc.h>
#include <string.h>
using namespace std;
//Coded By Hari Krishna Shah

/*Forward declaration of class cart so that class inventory can know that class cart exists somewhere
in the program and the class cart is its friend.*/
class cart;
class inventory{
	// making class cart as a friend class of class inventory so as to access the private data members of inventory class.
	friend class cart; 
	private:
		char product_name[100];
		float price;
		int reference_no;
	public:
		void get_details(char[], float, int);
		void display_inventory();
		int check_reference(int cart_ref);
	
};
int inventory::check_reference(int cart_ref){
	if(reference_no == cart_ref){
		return 1;
	}
	else{
		return 0;
	}
}
class cart{
	private:
		// creating int array to store reference numbers of the added items in the cart.
		int *cart_items; 
		float total_price;
	public:
		//Creating a constructor to dynamically allocate memory for the cart_items;
		cart(){
			// Default size of cart_items is enough to store 10 int numbers i.e 40 bytes total.
			cart_items = (int *) (malloc(10 * sizeof(int)));
			total_price = 0;
		}
		~cart(){
			free(cart_items);
		}
		void add_item(int, int);
		void display_cart(int, class inventory p[]);
		void check_out();
};

void inventory::get_details(char name[100], float p_price, int ref_no){
	strcpy(product_name, name);
	price = p_price;
	reference_no = ref_no;
}

void inventory::display_inventory(){
	cout<<"Product Name: "<<product_name<<endl;
	cout<<"Price: "<<price<<endl;
	cout<<"Reference Number: "<<reference_no;
}

void cart::add_item(int cart_ref, int cart_count){
	cart_items[cart_count + 1] = cart_ref;
	// Dynamically allocating memory for cart_item of the class cart
	cart_items = (int *) (realloc(cart_items, (cart_count + 10) * sizeof(int)));
	cout<<"Item added to your cart successfully."<<endl;
}


void cart::display_cart(int cart_count, class inventory p[]){
	float temp_price = 0;
	cout<<"Below is/are your cart-items."<<endl;
	for(int i = 0; i<=cart_count; i++){
		cout<<"Item number "<< i+1<<endl;
		for(int j = 0; j<5; j++){
			if(p[j].reference_no == cart_items[i]){
				p[j].display_inventory();
				temp_price += p[j].price;
				cout<<endl<<endl;
			}
		}
	}
	total_price = temp_price;
	cout<<"Total Price is RS "<<total_price<<endl;
}
void cart::check_out(){
	// Deleting the cart_items array elements and deallocating the memory.
	free(cart_items);
	// Allocating memory dynamically for cart_items array for further use.
	cart_items = (int *) (malloc(10 * sizeof(int)));
	cout<<"Thank you for shopping with us. !"<<endl;
	cout<<"Your cart items have been shipped and your cart has been emptied."<<endl;
	total_price = 0;
}

int main(){
	class inventory p[5];
	class cart cart_obj;
	int cart_ref, cart_count = -1; //cart_count is -1 signified the cart is emoty.
	p[0].get_details("Atheletic_Shoes", 2500, 1);
	p[1].get_details("Skipping_Rope", 500, 2);
	p[2].get_details("Cricket_Bat", 1500, 3);
	p[3].get_details("Football", 500, 4);
	p[4].get_details("Baseball_Bat", 1800, 5);

	int option = 0;
	while(option != -1){
		cout<<"\t\t\t***Welcome to the Shah Sports Store***\n"<<endl;
		cout<<"The following products are available with us currently."<<endl;
		for(int i = 0; i<5; i++){
			cout<<"Product Number - "<<i+1<<endl;
			p[i].display_inventory();
			cout<<endl<<endl;
		}
		cout<<"Please select an option from the menu below:\n \
		Enter 1 to add items to your cart\n \
		Enter 2 to view your cart\n \
		Enter 3 to checkout\n \
		Enter -1 to exit the store"<<endl;
		cout<<"Enter your option here: ";
		cin>>option;

		switch(option){
			case -1:{
				cout<<"Thank You for shopping with us."<<endl;
				break;
			}
			case 1:{
				int flag = 0;
				cout<<"Enter the reference number of the product that you want to add in your cart: ";
				cin>>cart_ref;
				for(int i = 0; i<5; i++){
					flag = p[i].check_reference(cart_ref);
					if(flag == 1){
						break;
					}
				}
				if(flag == 0){
					cout<<"Invalid Reference number. Try adding the item again."<<endl;
				}
				else{
					cart_obj.add_item(cart_ref, cart_count);
					cart_count += 1;
				}
				break;
			}
			
			case 2:{
				if(cart_count == -1){
					cout<<"The cart is empty. Please add some items in your cart first."<<endl;
				}
				else{
					cart_obj.display_cart(cart_count, p);
				}
				
				break;
			}
			case 3:{
				if(cart_count == -1){
					cout<<"The cart is empty. Please add some items in your cart first."<<endl;
				}
				else{
					cart_obj.display_cart(cart_count, p);
					cart_obj.check_out();
					cart_count = -1;
				}
				break;
			}
			
		}
	}
	return 0;
}
