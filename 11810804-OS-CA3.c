/*
	CSE325(Operating Systems)

This code is for the final submission of project of roll no-8 registration no.-11810804

Ques. 8. Sudesh Sharma is a Linux expert who wants to have an online system where he can handle student queries. Since there can be multiple requests at any time he wishes to dedicate a fixed amount of time to every request so that everyone gets a fair share of his time. He will log into the system from 10am to 12am only.  He wants to have separate requests queues for students and faculty. Implement a strategy for the same. The summary at the end of the session should include the total time he spent on handling queries and average query time.
*/

#include<stdio.h>
#include<string.h>
 
struct process_Struct {
    char process_name[20];
    int arrival_time, burst_time, completion_time, remaining;
}temp_Struct;
 

void student_Queue(int no_of_process) {
 
    int count, arrival_Time, burst_Time, quantum_time;
    struct process_Struct student_Process[no_of_process];
 
    for(count = 0; count < no_of_process; count++) {
        printf("Enter the details of Process[%d]", count+1);
        puts("");
        printf("Process Name : ");
        scanf("%s", student_Process[count].process_name);
 
        printf("Arrival Time : ");
        scanf("%d", &student_Process[count].arrival_time);
 
        printf("Burst Time : ");
        scanf("%d", &student_Process[count].burst_time);
    }
    printf("Now, enter the quantum time for STUDENT queue : ");
    scanf("%d", &quantum_time);
 
 
    // sorting the processes by their ARRIVAL time.
    // if the ARRIVAL time is same then scheduling is based on FCFS.
    for(count = 0; count < no_of_process; count++) {
        for(int x = count +1; x < count; x++){
            if(student_Process[count].arrival_time > student_Process[x].arrival_time) {
                temp_Struct = student_Process[count];
                student_Process[count] = student_Process[x];
                student_Process[x] = temp_Struct;
            }
        }
    }
 
    // initialy all the burst time is remaining and completion of process is zero.
    for(count = 0; count < no_of_process; count++) {
        student_Process[count].remaining = student_Process[count].burst_time;
        student_Process[count].completion_time = 0;
    }
 
    int total_time, queue, round_robin[20];
    total_time = 0;
    queue = 0;
    round_robin[queue] = 0;
}
 
 
 
int main(int argc, char const *argv[]) {
    int select_queue, no_of_process;
 
    puts("Please choose a queue to post your query : ");
    puts("1. FACULTY queue.");
    puts("2. STUDENT queue.");
    printf("> ");
    scanf("%d", &select_queue);
 
    switch(select_queue) {
        case 1 :
                printf("Enter number of process for FACULTY queue : ");
                scanf("%d", &no_of_process);
               
                faculty_Queue(no_of_process);
               
                break;
 
        case 2 :
                printf("Enter number of process for STUDENT queue : ");
                scanf("%d", &no_of_process);
 
                student_Queue(no_of_process);
               
                break;
 
        default :
                printf("Please selet the correct option by running the program again.");
    }
 
    return 0;
}

