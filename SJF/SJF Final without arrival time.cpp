#include <stdio.h>
#include <malloc.h>
// Shortest Job First
struct process{
	float brust_time;
	float waiting_time;
	float turn_around_time;
};

int main(){
	int size, *sequence;
	printf("Enter the number of processes: ");
	scanf("%d", &size);

	sequence = (int *) (malloc(size*sizeof(int)));

	struct process *p;
	p = (struct process *) (malloc(size * sizeof(struct process)));

	for(int i = 0; i<size; i++){
		printf("Enter the details for the process number %d below.\n", i);
		printf("Enter the brust time: ");
		scanf("%f", &p[i].brust_time);
		printf("\n");
	}
	for(int i = 0; i<size; i++){
		sequence[i] = i;
	}
	int temp;
	for(int i = 0; i<size; i++){
		for(int j = i+1; j<size; j++){
			if(p[(sequence[j])].brust_time<=p[(sequence[i])].brust_time){
				temp = sequence[i];
				sequence[i] = sequence[j];
				sequence[j] = temp;
			}
		}
	}
	printf("\n");
	printf("The sequence is : ");
	for(int i = 0; i<size; i++){
		printf("%P%d ", sequence[i]);
	}
	printf("\n");
	int time = 0;
		for(int i = 0; i<size; i++){
			time += p[(sequence[i])].brust_time;
			p[(sequence[i])].turn_around_time = time;
			p[(sequence[i])].waiting_time = time - p[(sequence[i])].brust_time;
		}

		printf("Process Number      Brust Time      Turn Around Time      Waiting Time\n");
		for(int i = 0; i<size; i++){
			printf("Process %d           %.2f             %.2f                  %.2f\n", i, p[i].brust_time, p[i].turn_around_time, p[i].waiting_time);
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
