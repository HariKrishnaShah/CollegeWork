#include<iostream>
#include<cstdlib>
using namespace std;
//Hari Krishna Shah
/* This is a program to illustrate the overloading of operators.
*/
class Fraction
{
     public:
          int num, deno;
     public:
          Fraction()
          {
               num = 1;
               deno = 1;
          }
          Fraction(int n, int d)
          {
               num = n;
               if (d==0)
               {
                    cout << "Error: Attempting to Divide by Zero" << endl;
                    exit(0); // it will terminate the program if division by 0 is attempted
               }
               else
                    deno = d;
          }
          Fraction operator +(Fraction f)
          {
               int n = num*f.deno+f.num*deno;
               int d = deno*f.deno;
               return Fraction(n/gcd(n,d),d/gcd(n,d));
          }
          Fraction operator -(Fraction f)
          {
               int n = num*f.deno-f.num*deno;
               int d = deno*f.deno;
               return Fraction(n/gcd(n,d),d/gcd(n,d));
          }
          Fraction operator *(Fraction f)
          {
               int n = num*f.num;
               int d = deno*f.deno;
               return Fraction(n/gcd(n,d),d/gcd(n,d));
          }
          Fraction operator /(Fraction f)
          {
               int n = num*f.deno;
               int d = deno*f.num;
               return Fraction(n/gcd(n,d),d/gcd(n,d));
          }
          bool operator == (Fraction &f)
          {
               return (num==f.num) && (deno==f.deno);
          }
          int gcd(int n, int d)
          {
               int rem;
               while (d != 0)
               {
                    rem = n % d;
                    n = d;
                    d = rem;
               }
               return n;
          }
          void accept()
          {
               cout<<"\n Enter Numerator     :  ";
               cin>>num;
               cout<<"\n Enter Denominator   :  ";
               cin>>deno;
          }
};
int main()
{
	cout<<" Digital Assignment Lab of OOP LAB"<<endl;
	class Fraction f[3];

	cout<<"\n Enter the value for the 1st Fraction below\n";

	f[1].accept();

	cout<<"\n Enter the value for the second Fraction below\n";
	f[2].accept();
	
	cout<<"\n -------------------------------------"<<endl;
	cout<<"\n The results of execution of overloaded arthimetic operators are given below: "<<endl;

	f[3]=f[1]+f[2];
	cout<<"\n -------------------------------------";
	cout<<"\n Sum of Two Numbers        : "<<f[3].num<<"/"<<f[3].deno<<endl;

	f[3]=f[1]-f[2];
	cout<<"\n Difference of Two Numbers : "<<f[3].num<<"/"<<f[3].deno<<endl;

	f[3]=f[1]*f[2];
	cout<<"\n Product of Two Numbers    : "<<f[3].num<<"/"<<f[3].deno<<endl;

	f[3]=f[1]/f[2];
	cout<<"\n Division of Two Numbers   : "<<f[3].num<<"/"<<f[3].deno;


     return 0;
}
