#include<iostream>
#include<string.h>
using namespace std;

class string_class
{
        char string[100];
    public:
        void operator!();    //Overloaded '!' Operator
        void get_details()
        {
                cout<<"\nEnter the string:  ";
                cin>>string;
        }
        void display_string()
        {
                cout<<string;
        }
};
void string_class::operator!()
{
	cout<<"\n\n The reversed string is given below:  "<<endl;
	int i = 0;

        while(string[i] != '\0')
        {
                if(string[i]>=65&&string[i]<=96)
                {
                        cout<<char(string[i]+32);
                }
                else if(string[i]>=97&&string[i]<=122)
                {
                        cout<<char(string[i]-32);
                }
                i++;
        }
}
int main()
{
	class string_class str;
	str.get_details();
    cout<<"\n\nThe entered string is  :  ";
    str.display_string();
    !str;
    return 0;
}
