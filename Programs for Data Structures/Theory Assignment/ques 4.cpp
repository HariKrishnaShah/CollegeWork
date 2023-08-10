#include <stdio.h>
#include <string.h>
//coded by Hari Krishna Shah
struct student{
		char name[100];
		int marks[3];
		char grade[3];
		float aggregate;
	};
void display(struct student temp);
int main(){
	int size, temp1 = 0, temp2 = 0 ,count = 0, count2 = 1;
	char search[100];
	printf("Enter the number of students: ");
	scanf("%d", &size);
	
	struct student s[size];
	
	for(int i = 0; i<size; i++){
		printf("Enter the details of student number %d below.\n", i+1);
		printf("Enter the name of student: ");
		scanf("%s", &s[i].name);
		printf("Enter the marks obtained in 3 subjects: ");
		for(int j = 0; j<3; j++){
			scanf("%d", &s[i].marks[j]);
		}
		printf("\n");
	}
	for(int j = 0; j<size; j++){
		for(int i = 0; i<3; i++){
			temp1 += s[j].marks[i];
			}
			temp2 = temp1/3;
			s[j].aggregate = temp2;
			if(temp2 >90){
				strcpy(s[j].grade, "A+");
			}
			else if(temp2 >80){
				strcpy(s[j].grade, "A");
			}
			else if(temp2 >70){
				strcpy(s[j].grade, "B+");
			}
			else if(temp2 >60){
				strcpy(s[j].grade, "B");
			}
			else if(temp2 >50){
				strcpy(s[j].grade, "C+");
			}
			else if(temp2 >40){
				strcpy(s[j].grade, "C");
			}
			else{
				strcpy(s[j].grade, "C");
				count += 1;
			}
			temp1 = 0;
	}
	
	if(count == 0){
		printf("There is no one in the class whose agrregate is below 40.\n\n");
	}
	else{
		printf("This are the students whose aggregate is less than 40.\n");
	for(int i = 0; i<size; i++){
		if(s[i].aggregate<40){
			printf("%d. %s\n", count2, s[i].name);
			count2 += 1;
		}
	}
	printf("\n");
	}
	
	int option = 0;
	while(option != -1){
		printf("Enter the name of student to search: ");
	scanf("%s", &search);
	for(int i = 0; i<size; i++){
		if(strcmp(s[i].name, search) == 0){
			display(s[i]);
		}
	}
	printf("Enter -1 to quit the program or any other integer to search again: ");
	scanf("%d", &option);
	printf("\n\n");
	}
	
	printf("The program exited succesfully.\n");

}

void display(struct student temp){
	printf("The details of the student is given below.\n");
	printf("Name: %s\n", temp.name);
	for(int j = 0; j<3; j++){
			printf("Marks for subject number %d: %d\n", j+1, temp.marks[j]);
	}
	printf("Grade: %s\n", temp.grade);
	printf("Aggregate: %.0f%%.\n", temp.aggregate);
}
