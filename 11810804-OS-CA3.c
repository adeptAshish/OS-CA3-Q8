/*
	CSE325(Operating Systems)

This code is for the final submission of project of roll no-8 registration no.-11810804

Ques. 8. Sudesh Sharma is a Linux expert who wants to have an online system where he can handle student queries.
Since there can be multiple requests at any time he wishes to dedicate a fixed amount of time to every request so that everyone gets a fair share of his time.
He will log into the system from 10am to 12am only.  He wants to have separate requests queues for students and faculty. Implement a strategy for the same. 
The summary at the end of the session should include the total time he spent on handling queries and average query time.
*/

#include<stdio.h>

int round_robin_algo(int limit){
    int i,total=0,error=0,x=limit,counter=0,time_quantum;
    int wait_time=0,turnaround_time=0,arrival_time[x],burst_time[x],temp[x];
    float average_wait_time, average_turnaround_time;
    
    for(i = 0; i < limit; i++)
      {
            printf("\nEnter Details of Process[%d]", i + 1);
            printf("\nArrival Time:");
            scanf("%d", &arrival_time[i]);
            printf("Burst Time:");
            scanf("%d", &burst_time[i]);
            if(burst_time[i]<0||arrival_time[i]<0){
		printf("\nERROR!!! The timings can not be negative.\n");
		error=1;
        	break;
        }
        else{
		temp[i] = burst_time[i];
		}
      }

	if(error==1){
	}
	else{
      printf("\nEnter Time Quantum: ");
      scanf("%d", &time_quantum);
      printf("\nProcess ID | Burst Time | Completion Time | Turnaround Time | Waiting Time");
      for(total = 0, i = 0; x!=0;)
      {
            if(temp[i] <= time_quantum && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  counter = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - time_quantum;
                  total = total + time_quantum;
            }
            if(temp[i] == 0 && counter == 1)
            {
                  x--;
                  printf("\nProcess[%d] |     %d      |      %d     |      %d    |     %d    ", i + 1, burst_time[i],total, total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
				  wait_time = wait_time + total - arrival_time[i] - burst_time[i];
                  turnaround_time = turnaround_time + total - arrival_time[i];
                  counter = 0;
            }
            if(i == limit - 1)
            {
                  i = 0;
            }
            else if(arrival_time[i + 1] <= total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }
      
    	average_wait_time = wait_time * 1.0 / limit;
    	average_turnaround_time = turnaround_time * 1.0 / limit;
    	printf("\nAverage Waiting Time: %f", average_wait_time);
    	printf("\nAverage Turnaround Time: %f", average_turnaround_time);
	}    
	return total;
} 

void faculity(int no){
	int time=round_robin_algo(no);
	if(time==0){}
	else{ 
	printf("\n\nOkay!   (o_o?) \nThe time it took to solve all your Queries was %dmin, I still have %dmin left.\n",time,120-time);
}
}

void student(int no){
	int time=round_robin_algo(no);
	if(time==0){}
	else{
	printf("\n\nOkay!   (o_o?) \nThe time it took to solve all your Queries was %dmin, I still have %dmin left.\n",time,120-time); 
}
}
 
void main() {
    int ask,select_queue, no_of_process;
 	printf("Good Morning People!!!\nMy name is Sudesh Sharma. I am your Linux instructor.\nI am here from 10am to 12am. So please make sure to ask your doubts before that.\n\nPress 1 to post your query : ");
 	scanf("%d",&ask);
 	
 	if(ask==1){
	printf("\nChoose a queue to post your query :\n1. Faculity queue\n2. Student queue.\n");
	scanf("%d", &select_queue);
 
    	switch(select_queue) {
        case 1 :
                printf("Enter number of process for FACULTY queue : ");
                scanf("%d", &no_of_process);
                faculity(no_of_process);              
                break;
         case 2 :
                printf("Enter number of process for STUDENT queue : ");
                scanf("%d", &no_of_process);
                student(no_of_process);  
                break;
        default :
                printf("Invalid Input!!! Try Again by recompiling the Code.");
    	}
	}
	else{
		printf("Invalid Input!!! Try Again by recompiling the Code.");
	}
}

