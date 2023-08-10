#include <stdio.h>
#include <malloc.h>
// Shortest Job First
struct process{
	float arrival_time;
	float brust_time;
	float waiting_time;
	float turn_around_time;
};

int main(){
	int size, *series;
	printf("Enter the number of processes: ");
	scanf("%d", &size);

	series = (int *) (malloc(size*sizeof(int)));

	struct process *p;
	p = (struct process *) (malloc(size * sizeof(struct process)));

	for(int i = 0; i<size; i++){
		printf("Enter the details for the process number %d below.\n", i);
		printf("Enter the arrival time: ");
		scanf("%f", &p[i].arrival_time);
		printf("Enter the brust time: ");
		scanf("%f", &p[i].brust_time);
		printf("\n");
	}
	for(int i = 0; i<size; i++){
		series[i] = i;
	}
	//
	int temp;
	int time_elapsed = 0;
	for(int i = 0; i<size; i++){
		for(int j = i+1; j<size; j++){
			if(p[(series[j])].arrival_time <= p[(series[i])].arrival_time){
				temp = series[i];
				series[i] = series[j];
				series[j] = temp;
			}
		}
	}
	for(int i = 0; i<size; i++){
		for(int j = i+1; j<size; j++){
			if(p[(series[j])].arrival_time == p[(series[i])].arrival_time){
				if(p[(series[j])].brust_time < p[(series[i])].brust_time){
					temp = series[i];
					series[i] = series[j];
					series[j] = temp;
				}
				
			}
		}
	}
	//
	printf("\n");
	printf("The sequence is : ");
	for(int i = 0; i<size; i++){
		printf("%P%d ", series[i]);
	}
	printf("\n");
	int time = 0;
		for(int i = 0; i<size; i++){
			time += p[(series[i])].brust_time;
			p[(series[i])].turn_around_time = time - p[(series[i])].arrival_time;
			p[(series[i])].waiting_time = time - p[(series[i])].brust_time- p[(series[i])].arrival_time;
		}

		printf("Process Number      Brust Time      Arrival Time      Turn Around Time      Waiting Time\n");
		for(int i = 0; i<size; i++){
			printf("Process %d           %.2f             %2.f             %.2f                  %.2f\n", i, p[i].brust_time, p[i].arrival_time, p[i].turn_around_time, p[i].waiting_time);
		}
		printf("\n");

		float total_turn_around_time = 0, average_turn_around_time, total_waiting_time = 0, average_waiting_time;

		for(int i = 0; i<size; i++){
			total_turn_around_time += p[i].turn_around_time;
			total_waiting_time += p[i].waiting_time;
		}
		average_turn_around_time = total_turn_around_time/size;
		average_waiting_time = total_waiting_time/size;

		printf("Total Turn around Time: %.3f\n", total_turn_around_time);
		printf("Average Turn around Time: %.3f\n", average_turn_around_time);
		printf("Total waiting Time: %.3f\n", total_waiting_time);
		printf("Average waiting Time: %.3f\n", average_waiting_time);


getchar();
return 0;


}
