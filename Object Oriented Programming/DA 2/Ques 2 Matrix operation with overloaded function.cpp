#include<iostream>
using namespace std;
//Coded by Hari Krishna Shah
 class mat
{
   private:
     int s[10][10];
     int r,c;
   public:
     void show();
     mat operator +(mat);
     mat operator *(mat);
     void read();
};
mat mat::operator+(mat obj)
{
    mat t;
    t.r=r;
    t.c=c;
    for(int i=0;i<t.r;i++)
         for(int j=0;j<t.c;j++){
         	t.s[i][j]=s[i][j]+obj.s[i][j];
		 }
		 return t;
}
mat mat::operator*(mat obj)
{
    mat t;
    t.r=r;
    t.c=obj.c;
    for(int i=0;i<t.r;i++){
    	for(int j=0;j<t.c;j++)
        {
	        t.s[i][j]=0;
	        for(int k=0;k<c;k++){
	        	t.s[i][j]+=s[i][k] * obj.s[k][j];
			}
	            
        }
	}
         
    return t;
}
void mat::read()
{
   cout<<"Enter Size of Matrix : \n";
   cin>>r>>c;
   cout<<"Enter the Elements of Matrix :\n";
   for(int i=0;i<r;i++){
   		for(int j=0;j<c;j++){
   		cin>>s[i][j];
		}
		
   }
        
}
void mat::show()
{
  for(int i=0;i<r;i++){
  		for(int j=0;j<c;j++){
  		cout<<s[i][j]<<"\t";
	    }
	  cout<<"\n";
    }
}
int main()
{
     mat obj1 ,obj2,obj3;
     cout<<"Enter First Matrix\n";
     obj1.read();
	 cout<<endl;
     cout<<"Enter Second Matrix\n";
     obj2.read();
     obj3=obj1 + obj2;
     cout<<"Result After Addition of two Matrix\n";
     obj3.show();
     obj3=obj1 * obj2;
     cout<<"Result After Multiplication of two Matrix\n";
     obj3.show();
}

