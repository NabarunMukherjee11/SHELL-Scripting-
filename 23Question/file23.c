/*
============================================================================
Name : file23.c
Author : Nabarun Mukherjee
Description : Write a program to create a Zombie state of the running program.
Date: 9th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	if(!fork()){
		printf("the child process PID is %d\n", getpid());
	}
	else{	
		printf("the parent process PID is %d\n", getpid());
		sleep(60);
		printf("parent out of sleep");
		int child_id=wait(0);
		printf("Zombie id %d\n", child_id);
	}
	return 0;
}
