/*
============================================================================
Name : file30.c
Author : Nabarun Mukherjee
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 9th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>
#include<fcntl.h>
int main(){
	if(!fork()){
		printf("the child process with %d process id will be made the daemon process\n", getpid());
		umask(0);
        	pid_t pid, setid;
       		pid=getpid();
       		setid=setsid();
		chdir("/");
        	while(1){
                	time_t now= time(NULL);
                	struct tm *tm_info=localtime(&now);
                	if(tm_info->tm_sec%10==5){
                        	int fd=open("/home/nabarunmukherjee/SoftwareSystems/SHELL-Scripting-/30Question/file30.txt", O_RDWR | O_APPEND);
				char buff[5]="abcg";
				write(fd, buff, strlen(buff));
                   
                	}
        	}
	}
	else{
		printf("the parent process with %d process id is terminated\n", getpid());
		return 1;
	}
	return 0;
}
