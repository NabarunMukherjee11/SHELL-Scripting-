/*
============================================================================
Name : file113.c
Author : Nabarun Mukherjee
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 9th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> //for file descriptor
#include<sys/time.h> // for struct timeval
#include<sys/types.h> // for fd_set and select

int main(){
	fd_set readfds;
	FD_ZERO(&readfds);
	FD_SET(STDIN_FILENO, &readfds);

	int nfds=STDIN_FILENO+1;

	struct timeval timeout;
	timeout.tv_sec=10;
	timeout.tv_usec=0;
	
	int retval=select(nfds, &readfds, NULL, NULL, &timeout);
	if(retval){
		printf("the data was input within 10 seconds\n");
	}
	else{
		printf("the data was not input in 10 seconds\n");
	}
	return 0;
	}

		
