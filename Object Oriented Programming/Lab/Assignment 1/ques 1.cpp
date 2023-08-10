#include <iostream>
using namespace std;
//Coded by Hari Krisnna Shah
void get_gcd_and_lcm(int &gcd, int &lcm, int num1, int num2);
int main(){
	int hcf, lcm;
	int num1, num2;
	cout<<"Enter two numbers to calculate gcd and lcm: ";
	cin>>num1>>num2;
	
	get_gcd_and_lcm(hcf, lcm, num1, num2);
	
	cout<<"The gcd and lcm of the two number "<<num1<<" and "<<num2<<" are given below."<<endl;
	cout<<"GCD: "<<hcf<<endl;
	cout<<"LCM: "<<lcm<<endl;
}

void get_gcd_and_lcm(int &gcd, int &lcm, int num1, int num2){
	int i = 1;
	int j = 1;
	
	while(i<=num1 && i<=num2){
		if((num1%i == 0) && (num2%i == 0)){
			gcd = i;
		}
		 i += 1;
	}
	
	j = 1;
	while((j%num1 != 0) || ( j%num2 != 0)){
		j += 1;
	}
	lcm = j;
	
}
