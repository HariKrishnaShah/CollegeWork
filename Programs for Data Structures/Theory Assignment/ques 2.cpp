#include <stdio.h>
//Coded by Hari Krishna Shah

int main(){
	int MARKS[20][5], average_for_student[20] = {0}, average_marks= 0, scored_below = 0;
	int subject_average[5]={0}, sum_for_student = 0, sum_subject_average = 0, sum_marks = 0, total_for_student[20] = {0};
	
	for(int i = 0; i<20; i++){
		printf("Enter the marks scored by student number %d in 5 subjects: ", i+1);
		for(int j = 0; j<5; j++){
			scanf("%d", &MARKS[i][j]);
		}
	}
	
	for(int i = 0; i<20; i++){
		for(int j = 0; j<5; j++){
			sum_for_student += MARKS[i][j];
		}
		total_for_student[i] = sum_for_student;
		average_for_student[i] = sum_for_student/5;
		sum_for_student = 0;
	}
	for(int i = 0; i<20; i++){
		for(int j = 0; j<5; j++){
			sum_marks += MARKS[i][j];
		}
		average_marks = sum_marks/100;
	}
	for(int j = 0; j<5; j++){
		for(int i = 0; i<20; i++){
			sum_subject_average += MARKS[i][j];
		}
		subject_average[j] =sum_subject_average/20;
		sum_subject_average = 0;
	}
	
	for(int i = 0; i<20; i++){
		if(average_for_student[i]<50){
			scored_below += 1;
		}
	}
	
	printf("\n");
	for(int i = 0; i<5; i++){
		printf("The average marks scored in subject number %d is: %d\n", i+1, subject_average[i]);
	}
	printf("\n");
	printf("The average score of the class per subject is %d.\n", average_marks);
	printf("The number of student whose average is less than 50 is %d.\n\n", scored_below);
	for(int i = 0; i<20; i++){
		printf("The marks scored by student number %d is given below: \n", i+1);
		for(int j = 0; j<5; j++){
			printf("Marks for subject number %d is %d.\n", j+1, MARKS[i][j]);
		}
		printf("The total marks scored by student number %d is %d.\n", i+1, total_for_student[i]);
		printf("The average marks scored by student number %d is %d.\n", i+1, average_for_student[i]);
		printf("\n");
	}
	
	
	
	return 0;
}
