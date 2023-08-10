/*Ques 1. Construct an OOP to find the distance travelled by a Vehicle in “t”
seconds is given by
 Distance = u x t = ( (a x t2) / 2 ).
Here, “u” is the initial velocity (meters per second) and “a” is the
acceleration (meters per second2). Write an OOP to evaluate the
distance travelled at regular intervals of time, given the values of “u”
and “a”. The program should provide the flexibility to the user to select
their own time intervals and repeat the calculations for different
values of “u” and “a” and tabulate the result.
*/


#include <iostream>
#include <malloc.h>
using namespace std;

class calculation{
		private:
			float initial_velocity;
			float time;
			float acceleration;
			float distance;
			float total_distance;

		public:
			void get(){
				cout<<"Please enter the following details to calculate the distance travelled."<<endl;
				cout<<"Enter the initial velocity in m/s: ";
				cin>>initial_velocity;
				cout<<"Enter the time in seconds: ";
				cin>>time;
				cout<<"Enter the accleration in m/s^2: ";
				cin>>acceleration;
			}

			float distance_travelled(){
				float d;
				d = (initial_velocity*time) + (0.5* (acceleration * time*time));
				distance = d;
				return d;
			}

			void display(){
				cout<<"The intial veloctiy is "<<initial_velocity<<" m/s."<<endl;
				cout<<"The time taken is "<<time<<" seconds."<<endl;
				cout<<"The acceleration is "<<acceleration<<" m/s^2."<<endl;
				cout<<"The distance travelled is "<<distance<<" meters."<<endl;
				cout<<"The total distance travelled till this interval is "<<total_distance<<" meters."<<endl;

			}
			void insert_total_distance_travelled(float total_distance_travelled){
				total_distance = total_distance_travelled;
			}

			float get_total_distance_travelled(){
				return total_distance;
			}
	};

int main(){
	class calculation *interval;
	interval = (class calculation *) (malloc(sizeof(class calculation)));
	float answer, total_d;
	static int interval_count = 0;
	int option;
	do{
		cout<<"\t\t\tThis program was made by Hari Krishna Shah !!!"<<endl;
		cout<<"Welcome to the Main Menu."<<endl;
		cout<<"Choose an option to carry out an operation.\n\
		Enter 1 to perform a calculation.\n \
		Enter 2 to tabulate the result.\n \
		Enter 3 to quit the program."<<endl;
		cout<<"Enter you option here: ";
		cin>>option;

		switch(option){
			case 1 :
				interval = (class calculation *) (realloc(interval, (interval_count + 1)*sizeof(class calculation)));
				interval[interval_count].get();
				answer = interval[interval_count].distance_travelled();
				cout<<"The distance travalled is "<<answer<<" meters."<<endl;
				if(interval_count == 0){
					total_d = answer;
					interval[interval_count].insert_total_distance_travelled(total_d);
				}
				else{
					total_d = answer + interval[interval_count-1].get_total_distance_travelled();
					interval[interval_count].insert_total_distance_travelled(total_d);
				}
				cout<<"The total distance travelled till this interval is "<<total_d<<" meters.\n"<<endl;
				interval_count += 1;
				break;
			case 2:
				if(interval_count == 0){
					cout<<"The calculations are empty. Do some calculations first.\n"<<endl;
				}
				else{
					for(int i = 0; i<interval_count; i++){
					cout<<"The details of the interval number "<<i+1<<" is given below."<<endl;
					interval[i].display();
					cout<<endl;
				}
				}
				break;
			case 3:
				break;
			default:
				cout<<"Enter a valid option and try again.\n"<<endl;

		}
		cout<<endl;
	}
	while(option != 3);

	delete interval;
	cout<<"This program was made with love by Hari Krishna Shah.\nPlease drop a review or a feedback.\nThank You !"<<endl;
	return 0;
}


