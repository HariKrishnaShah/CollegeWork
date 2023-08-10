/*Ques 2. At the end of every semester, a Faculty wants to prepare the Grade
for the all student based on their scores in Internal Assessment Test1, Internal Assessment Test-2 and Final Assessment Test. These test
marks are scored out of 100 and stored as Mark1, Mark2 and Mark3
against the respective student RegNo, Name and Government Identity
Number (like Aathar No, Driving License No, Passport No etc…)
respectively. Every student’s grade will be calculated based on their
Page 2 of 2
average score in all the three marks. If the average score is >=90.0, the
grade is ‘S’ and if the average score is >=80.0, the grade is ‘A’.
Similarly, if the score is >=70.0, 60.0 and 50.0, the grade is assigned
as ‘B’, ‘C’ and ‘D’ respectively. Otherwise, Grade is marked as ‘F’.
Develop an object oriented program using classes and objects. Include
the union to hold any one government Id card.
*/

#include <iostream>
#include <malloc.h>
#include <string.h>
using namespace std;

class students{
	private:
		char name[50];
		float marks[3];
		float total_marks;
		float average;
		char grade[5];
		int ID_Specifier; // 1 means Aaathar_no, 2 means Driving_License_no and 3 means Passport_no
		union Government_Identity{
			int Aathar_no;
			int Driving_License_no;
			int Passport_no;
		}id;
	public:
		void get_details();
		void marks_calulations();
		void display_details();
		int search_name(char input_name[50]);
	
};

void students::get_details(){
	cout<<"Enter the student's name: ";
	cin>>name;
	cout<<"Choose the government identity type.\nEnter 1 for Aathar, 2 for Driving License and 3 for Passport number: ";
	cin>>ID_Specifier;
	cout<<"Enter the ID number: ";
	cin>>id.Aathar_no;
	cout<<"Enter the marks obtained in three subjects: ";
	for(int i = 0; i<3; i++){
		cin>>marks[i];
	}
	cout<<"All the details of this student have been collected successfully.\n"<<endl;
	
}

void students::marks_calulations(){
	float total = 0;
	for(int i = 0; i<3; i++){
		total += marks[i];
	}
	total_marks = total;
	average = total/3;
	if(average>=90){
		strcpy(grade, "S");
	}
	else if(average>=80){
		strcpy(grade, "A");
	}
	else if(average>=70){
		strcpy(grade, "B");
	}
	else if(average>=60){
		strcpy(grade, "C");
	}
	else if(average>=50){
		strcpy(grade, "D");
	}
	else{
		strcpy(grade, "F");
	}
}

void students::display_details(){
	cout<<"Name: "<<name<<endl;
	for(int i = 0; i<3; i++){
		cout<<"Marks in subject number "<<i+1<<" : "<<marks[i]<<"."<<endl;
	}
	cout<<"Total Marks: "<<total_marks<<endl;
	cout<<"Average: "<<average<<endl;
	cout<<"Grade: "<<grade<<endl;
	if(ID_Specifier==1){
		cout<<"Aathar number: "<<id.Aathar_no<<endl;
	}
	if(ID_Specifier==2){
		cout<<"Driving License number: "<<id.Aathar_no<<endl;
	}
	if(ID_Specifier==3){
		cout<<"Passport number: "<<id.Aathar_no<<endl;
	}
}
int students::search_name(char input_name[50]){
			if(strcmp(input_name, name) ==0){
				return 1;
			}
			else{
				return 0;
			}
}
		
int main(){
	class students *s;
	s = (class students *) (malloc(sizeof(class students)));
	static int student_count = 0;
	int temp1_count=0, temp2_count = 0;
	int option = 0;
	char name[50];
	
	while(option != -1){
		int search_result = 0;
		cout<<"\t\t\tThis program is created by Hari Krishna Shah."<<endl;
		cout<<"Welcome to the Main Menu !!"<<endl;
		cout<<"Please choose an option\n \
		Enter 1 to create or add report of multiple students\n \
		Enter 2 to display the details of all the students\n \
		Enter 3 to search the detail of a student\n \
		Enter -1 to quit the program"<<endl;
		cout<<"Enter an option: ";
		cin>>option;
		switch(option){
			case 1:
				cout<<"Enter the number of student whose report is to prepared: ";
				cin>>temp2_count;
				student_count += temp2_count;
				cout<<endl;
				s = (class students *) (realloc(s, student_count * sizeof(class students)));
				for(; temp1_count<student_count; temp1_count++){
					cout<<"Enter the details of student number "<<temp1_count+1<<endl;
					s[temp1_count].get_details();
					s[temp1_count].marks_calulations();
				}
				break;
			case 2:
				if(student_count == 0){
					cout<<"There isn't any student in the class. Please add some students first"<<endl;
				}
				for(int i = 0; i<student_count; i++){
					cout<<"\nThe detail of student number "<<i+1<<" is below."<<endl;
					s[i].display_details();
				}
				break;
			case 3:
				if(student_count == 0){
					cout<<"There isn't any student in the class. Please add some students first"<<endl;
				}
				else{
					cout<<"Enter the name of the student to search: ";
					cin>>name;
					cout<<endl;
					for(int i = 0; i<student_count; i++){
						search_result = s[i].search_name(name);
						if(search_result == 1){
							s[i].display_details();
						}
					}
					if(search_result ==0){
						cout<<"The searched name was not found. Please try again with another name."<<endl;
					}
				}
				break;
			case -1:
				break;
			default:
				cout<<"Please enter a valid address and try again."<<endl;
		}
		cout<<endl;
		
	}
	delete s;
	cout<<"This program was made with love by Hari Krishna Shah.\nPlease drop a review or a feedback.\nThank You !"<<endl;
	return 0;
}

