#include <stdio.h>
#include <stdbool.h>
//Premptitive SRTF

struct process{
	float brust_time;
	float arrival_time;
	float turn_around_time;
	float waiting_time;
	float remaining_time;
	bool completed;
};

int main(){
	int num, time = 0, now = 0;
	struct process *p;
	printf("Enter the number of processes: ");
	scanf("%d", &num);
	p = (struct process *) (malloc(num*sizeof(struct process)));
	
	for(int i = 0; i<num; i++){
		printf("Enter the details for the process number %d below:\n");
		printf("Enter the arrival time: ");
		scanf("%f", &p[i].arrival_time);
		printf("Enter the brust time: ");
		scanf("%f", &p[i].brust_time);
		p[i].remaining_time = p[i].brust_time;
		p[i].completed = false;
	}
	for(int i = 0; i<num; i++){
		if(p[i].arrival_time<=time){
			if(p[i].completed == false){
				now = i;
				for(int j = 0; j<size; j++){
					if(p[j].remaining_time<=p[i].reamining_time && p[j].completed == false){
						now = j;
					}
				}
				time = p[now].
			}
		}
	}
	
}
