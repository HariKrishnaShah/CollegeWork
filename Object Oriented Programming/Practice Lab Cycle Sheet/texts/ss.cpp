#include<fstream>
#include<conio.h>
 #include<string.h>
 #include<iomanip>
 #include<iostream>
using namespace std;
class product
 {
 int product_number;
 char product_name[50];
 float product_price,product_quantity,tax,product_discount;
o public:
o
o
o void create_product()
o {
o cout<<endl<<"Please Enter The Product Number: ";
o cin>>product_number;
o cout<<endl<<"Please Enter The Name of The Product: ";
o cin.ignore();
o cin.getline(product_name ,50);
o cout<<endl<<"Please Enter The Price of The Product: ";
o cin>>product_price;
o cout<<endl<<"Please Enter The Discount (%): ";
o cin>>product_discount;
o }
o
o void show_product()
o {
o cout<<endl<<"Product #: "<<product_number;
o cout<<endl<<"Product Name: "<<product_name;
o cout<<endl<<"Product Price: "<<product_price;
o cout<<endl<<"Discount : "<<product_discount;
o }
o
o int getProduct()
o {
o return product_number;
o }
o
o float getPrice()
o {
o return product_price;
o }
o
o char* getName()
o {
o return product_name;
o }
o
o float getDiscount()
o {
o return product_discount;
o }
o };
o
o
o
o fstream fp;
o product produc;
o
o
o void save_product()
o {
o fp.open("database.dat",ios::out|ios::app);
o produc.create_product();
o fp.write((char*)&produc,sizeof(product));
o fp.close();
o cout<<endl<<endl<<"The Product Has Been Sucessfully Created...";
o getchar();
o } o o void show_all_product() o { o system("cls"); o cout<<endl<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"; o cout<<endl<<"\t\tRECORDS."; o cout<<endl<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"; o fp.open("database.dat",ios::in); o while(fp.read((char*)&produc,sizeof(product))) o { o produc.show_product(); o cout<<endl<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"<<endl; o getchar(); o } o fp.close(); o } o o void display_record(int num) o { o bool found=false; o fp.open("database.dat",ios::in); o while(fp.read((char*)&produc,sizeof(product))) o { o if(produc.getProduct()==num)
o {
o system("cls");
o produc.show_product();
o found=true;
o }
o }
o
o fp.close();
o if(found == true)
o cout<<"\n\nNo record found";
o getchar();
o }
o
o
o void edit_product()
o {
o int num;
o bool found=false;
o system("cls");
o cout<<endl<<endl<<"\tPlease Enter The Product #: ";
o cin>>num;
o
o fp.open("database.dat",ios::in|ios::out);
o while(fp.read((char*)&produc,sizeof(product)) && found==false)
o {
o if(produc.getProduct()==num)
o {
o produc.show_product();
o cout<<"\nPlease Enter The New Details of Product: "<<endl;
o produc.create_product();
o int pos=-1*sizeof(produc);
o fp.seekp(pos,ios::cur);
o fp.write((char*)&produc,sizeof(product));
o cout<<endl<<endl<<"\t Record Successfully Updated...";
o found=true;
o }
o }
o fp.close();
o if(found==false)
o cout<<endl<<endl<<"Record Not Found...";
o getchar();
o }
o
o
o
o void delete_product()
o {
o int num;
o system("cls");
o cout<<endl<<endl<<"Please Enter The product #: ";
o cin>>num;
o fp.open("database.dat",ios::in|ios::out);
o fstream fp2;
o fp2.open("Temp.dat",ios::out);
o fp.seekg(0,ios::beg);
o while(fp.read((char*)&produc,sizeof(product)))
o {
o if(produc.getProduct()!=num)
o {
o fp2.write((char*)&produc,sizeof(product));
o }
o }
o fp2.close();
o fp.close();
o remove("database.dat");
o rename("Temp.dat","database.dat");
o cout<<endl<<endl<<"\tRecord Deleted...";
o getchar();
o }
o
o
o void product_menu()
o {
o system("cls");
o fp.open("database.dat",ios::in);
o
o cout<<endl<<endl<<"\t\tProduct MENU\n\n";
o cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
o cout<<"P.NO.\t\tNAME\t\tPRICE\n";
o cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
o while(fp.read((char*)&produc,sizeof(product)))
o {
o cout<<produc.getProduct()<<"\t\t"<<produc.getName()<<"\t\t"<<produc.getPrice()<<endl;
o }
o fp.close();
o }
o
o
o
o void place_order()
o {
o int order_arr[50],quan[50],c=0;
o float amt,damt,total=0;
o char ch='Y';
o product_menu();
o cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
o cout<<"\n PLACE YOUR ORDER";
o cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
o do{
o cout<<"\n\nEnter The Product #: ";
o cin>>order_arr[c];
o cout<<"\nQuantity: ";
o cin>>quan[c];
o c++;
o cout<<"\nDo You Want To Order Another Product ? (y/n)";
o cin>>ch;
o }while(ch=='y' ||ch=='Y');
o cout<<"\n\nThank You...";
o getchar();
o system("cls");
o cout<<"\n\n********************************INVOICE************************\n";
o cout<<"\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\n";
o for(int x=0;x<=c;x++)
o {
o fp.open("database.dat",ios::in);
o fp.read((char*)&produc,sizeof(product));
o while(!fp.eof())
o {
o if(produc.getProduct()==order_arr[x])
o {
o amt=produc.getPrice()*quan[x];
o damt=amt-(amt*produc.getDiscount()/100);
o cout<<"\n"<<order_arr[x]<<"\t"<<produc.getName()<<"\t"<<quan[x]<<"\t\t"<<produc.getPrice()<<"\t"<<amt<<"\t\t"<<damt;
o total+=damt;
o }
o fp.read((char*)&produc,sizeof(product));
o }
o fp.close();
o }
o cout<<"\n\n\t\t\t\t\tTOTAL = "<<total;
o getchar();
o }
o
o
o
o void admin_menu()
o {
o system("cls");
o int option;
o cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
o cout<<"\n\tPress 1 to CREATE PRODUCT";
o cout<<"\n\tPress 2 to DISPLAY ALL PRODUCTS";
o cout<<"\n\tPress 3 to QUERY ";
o cout<<"\n\tPress 4 to MODIFY PRODUCT";
o cout<<"\n\tPress 5 to DELETE PRODUCT";
o cout<<"\n\tPress 6 to GO BACK TO MAIN MENU";
o cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
o
o cout<<"\n\n\tOption: ";
o cin>>option;
o switch(option)
o {
o case 1: system("cls");
o save_product();
o break;
o
o case 2: show_all_product();
o break;
o
o case 3:
o int num;
o system("cls");
o cout<<"\n\n\tPlease Enter The Product Number: ";
o cin>>num;
o display_record(num);
o break;
o
o case 4: edit_product();
o break;
o
o case 5: delete_product();
o break;
o
o case 6: system("cls");
o break;
o
o default:admin_menu();
o }
o }
o
o
o int main(int argc, char *argv[])
o {
o system("cls");
o system("color 05");
o cout<<"\t\t\t\t*\t*";
o cout<<"\t\t\t\t**\t**";
o cout<<"\t\t\t\t***\t***";
o cout<<"\t\t\t\t****\t****";
o cout<<"\t\t\t\t*****\t*****";
o cout<<"\t\t\t\t******\t******";
o cout<<"\t\t\t\t*******\t*******";
o cout<<"\t\t\t\t*******\t*******";
o cout<<"\t\t\t\t******\t******";
o cout<<"\t\t\t\t*****\t*****";
o cout<<"\t\t\t\t****\t****";
o cout<<"\t\t\t\t***\t***";
o cout<<"\t\t\t\t**\t**";
o cout<<"\t\t\t\t*\t*";
o int option;
o string password="admin@123";
o string password1;
o
o {
o
o cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
o cout<<"\n\t1. CUSTOMER";
o cout<<"\n\t2. ADMINISTRATOR";
o cout<<"\n\t3. EXIT";
o cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
o
o cout<<"\n\tOption: ";
o cin>>option;
o
o switch(option)
o {
o case 1: system("cls");
o place_order();
o getchar();
o break;
o case 2:
o cout<<"\n \tKindly enter Password: "; o cin>>password1; o if(password==password1){ o admin_menu(); o } o else { o cout<<" \t\t**Invalid Password...**\n"; o } o break; o o case 3: o cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"; o cout<<"\n\tGood Bye! Have a Nice Day."; o cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"; o exit(0); o o default :cout<<"Invalid Input...\n"; o } o o } o }
OUTPUT:
?

?


