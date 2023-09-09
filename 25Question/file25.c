/*
============================================================================
Name : file25.c
Author : Nabarun Mukherjee
Description : Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 9th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
	int cp1, cp2, cp3;
	if(!(cp1=fork())){
		printf("inside child process 1 with pid %d\n", getpid());
		sleep(30);
		printf("child 1 with PID %d completes execution\n", getpid());
		return 0;
	}
	else if(!(cp2=fork())){
		printf("inside child process 2 with pid %d\n", getpid());
                sleep(15);
                printf("child 2 with PID %d completes execution\n", getpid());
                return 0;
        }
	else if(!(cp3=fork())){
		printf("inside child process 3 with pid %d\n", getpid());
                sleep(40);
                printf("child 3 with PID %d completes execution\n", getpid());
                return 0;
        }
	else{
		printf("which child process  should we wait for %d or %d or %d?\n", cp1, cp2, cp3);
		int pid, status;
		scanf("%d", &pid);
		if(pid==cp1 || pid==cp2 || pid==cp3){
			int ter=waitpid(pid, &status, 0);
			printf("we terminated %d\n", ter);
			printf("parent process completes execution");
			return 0;
			}
		else{
			printf("you enter wrong choice");
			}
		return 0;
		}
	}

	

	
