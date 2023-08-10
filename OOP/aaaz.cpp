#include <stdio.h>
#include <string.h>

struct details{
	char name[200];
	int id;
	int marks[5];
};

int main(){
	struct details d[2];
	
	for(int i = 0; i<2; i++){
		printf("Enter the detail of student number %d below.\n", i+1);
		printf("Enter name: ");
		scanf("%s", &d[i].name);
		printf("Enter the id: ");
		scanf("%d" , &d[i].id);
		printf("\n\n");
		for(int j = 0; j<5; j++){
			printf("Enter the marks of subject number %d : ", j+1);
			scanf("%d", &d[i].marks[j]);
		}
	}
	
	for(int i= 0; i<2; i++){
		printf("Details of student number %d is given below.\n", i+1);
		printf("Name: %s\n", d[i].name);
		printf("Id: %d\n", d[i].id);
		for(int j = 0; j<5; j++){
			printf("Marks for subject number %d: %d.\n", i+1, d[i].marks[j]);
		}
	}
	
	
	return 0;
	
}
