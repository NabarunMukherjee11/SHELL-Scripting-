/*
============================================================================
Name : file29.c
Author : Nabarun Mukherjee
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 9th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sched.h>

int main(){
	pid_t process_id=getpid();
	int current_policy;
	current_policy=sched_getscheduler(process_id);
	switch(current_policy){
		case SCHED_FIFO: printf("The current proces is scheduled in SCHED_FIFO\n"); break;
		case SCHED_RR: printf("The current process is scheduled in SCHED_RR\n"); break;
		case SCHED_OTHER: printf("The current process is scheduled in SCHED_OTHER\n"); break;
		default: printf("The current process is scheduled in an unknown scheduling policy"); break;
		}
	sleep(5);
	printf("We can change the scheduling policy of the process\n");
	printf("Press 1 to change priority to SCHED_FIFO\n");
	printf("Press 2 to change priority to SCHED_RR\n");
	int x;
	scanf("%d", &x);
	switch(x){
		case 1: current_policy=SCHED_FIFO; break;
		case 2: current_policy=SCHED_RR; break;
		default: printf("Wrong choice\n"); return 1;  break;
	}
	struct sched_param param;
	param.sched_priority = 99;
	switch(x){
		case 1: current_policy=SCHED_FIFO; break;
		case 2: current_policy=SCHED_RR; break;
		default: printf("Wrong choice\n"); return 0; break;
	}
	int xi=sched_setscheduler(process_id, current_policy, &param);
	if(xi){
		printf("The set_scheduler not working\n");
		perror("sched_setscheduler");
		return 1;
	}
	int new_policy;
	new_policy=sched_getscheduler(process_id);
	switch(new_policy){
                case SCHED_FIFO: printf("The new proces is scheduled in SCHED_FIFO\n"); break;
                case SCHED_RR: printf("The new process is scheduled in SCHED_RR\n"); break;
                default: printf("The new process is scheduled in an unknown scheduling policy"); break;
                }
	return 0;
}

