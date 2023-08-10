#include <iostream>
#include <cstring>
using namespace std;
//Coded by Hari Krishna Shah
class time{
	private:
		char name[50];
		float time_taken[5];
		float average_time;
		float total_time;
	public:
		void get_details();
		void calculate_time();
		void display_all();
		void compare(class time b);
};

int main(){
	class time t[2];
	cout<<"\t\tThis program compares two time objects and provides statistics based on the comparision."<<endl;
	for(int i = 0; i<2; i++){
		cout<<"Enter the details for the object number "<< i+1 <<" below."<<endl;
		t[i].get_details();
		t[i].calculate_time();
		cout<<endl;
	}
	
	for(int i = 0; i<2; i++){
		cout<<"The calculated details for the object number "<<i+1<<" is given below."<<endl;
		t[i].display_all();
		cout<<endl<<endl;
	}
	
	cout<<"The detailed comparision between the two objects is given below."<<endl;
	t[0].compare(t[1]);
	return 0;
}

void time::get_details(){
	cout<<"Enter the name for the worker: ";
	cin>>name;
	cout<<"Enter the time take taken by "<<name<<" to do the 5 tasks below in terms of hours."<<endl;
	for(int i = 0; i<5; i++){
		cout<<"Time Taken to do task "<<i+1<<" in terms of hours: ";
		cin>>time_taken[i];
	}
	cout<<"All details collected successfully."<<endl<<endl;
}

void time::calculate_time(){
	float total_temp=0, average_temp;
	
	for(int i = 0; i<5; i++){
		total_temp += time_taken[i];
	}
	average_temp = total_temp/5;
	total_time = total_temp;
	average_time = total_time/5;
}

void time::display_all(){
	cout<<"The details of time taken by "<<name<<" to do 5 tasks are given below."<<endl;
	cout<<"Name: "<<name<<endl;
	for(int i = 0; i<5; i++){
		cout<<"Time taken for task"<<i+1<<" in hours:"<<time_taken[i]<<endl;
	}
	cout<<"Total time taken to do 5 tasks in hours: "<<total_time<<endl;
	cout<<"Average time taken to finish a task in hours: "<<average_time<<endl;
}

void time::compare(class time b){
	float percent;;
	for(int i = 0; i<5; i++){
		if(time_taken[i]>b.time_taken[i]){
			cout<<b.name<<" does the task"<<i+1<<" faster than "<<name<<" ."<<endl;
			cout<<b.name<<" takes just "<<b.time_taken[i]<<" hours to do the task"<<i+1<<" but "<<name<<" takes "<<time_taken[i]<<" hours to do the same task"<<endl;
			cout<<endl;
		}
		else if(time_taken[i]<b.time_taken[i]){
			cout<<name<<" does the task"<<i+1<<" faster than "<<b.name<<" ."<<endl;
			cout<<name<<" takes just "<<time_taken[i]<<" hours to do the task"<<i+1<<" but "<<b.name<<" takes "<<b.time_taken[i]<<" hours to do the same task"<<endl;
			cout<<endl;
		}
		else{
			cout<<"Both "<<name<<" and "<<b.name<<" take equal time of "<<b.time_taken[i]<<" hours to do the task"<<i+1<<" ."<<endl;
			cout<<endl;
		}
	}
	cout<<endl<<endl;
	cout<<name<<" can finish all the 5 tasks in "<<total_time<<" hours and "<<b.name<<" needs "<<b.total_time<<" hours to do all the 5 tasks."<<endl;
	cout<<name<<" takes "<<average_time<<" hours on average to do a task and "<<b.name<<" needs "<<b.average_time<<" hours on average to finish a task.";
	cout<<endl;
	if(total_time>b.total_time){
		percent = (total_time/b.total_time)*100;
		cout<<b.name<<" is "<<percent-100<<"% faster than "<<name<<endl;
	}
	else if(b.total_time>total_time){
		percent = (b.total_time/total_time)*100;
		cout<<name<<" is "<<percent-100<<"% faster than "<<b.name<<endl;
	}
	else{
		cout<<"Both "<<name<<" and "<<b.name<<" have the same working speed."<<endl;
	}
	
}
