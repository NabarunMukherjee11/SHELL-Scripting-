/*
============================================================================
Name : file120.c
Author : Nabarun Mukherjee
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 9th Sep, 2023.
============================================================================
*/

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/resource.h>

int main(){
	int curr_priority;
	id_t which = getpid();
	curr_priority= getpriority(PRIO_PROCESS, which);
	//we can also get priority using nano(0)
	if(curr_priority==-1){
		printf("Error getting the priority value\n");
		return 1;
	}
	printf("The current Priority or niceness is %d\n", curr_priority);

	int updated_priority=nice(10);
	if(updated_priority==-1){
		printf("The process priority is not updated\n");
		return 1;
	}

	printf("The updated Priority or niceness is %d\n", updated_priority);
	return 1;
}


