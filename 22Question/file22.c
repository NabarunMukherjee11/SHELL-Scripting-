/*
============================================================================
Name : file22.c
Author : Nabarun Mukherjee
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file. 
Date: 28th Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
int main(int argc, char *argv[]){
	if(argc!=2){
		printf("Give a file name");
		return 0;
	}
	char *filename=argv[1];
	int fd=open(filename, O_WRONLY | O_APPEND);
	if(fd==-1){
		printf("File Descriptor not working\n");
		return 0;
	}

	pid_t process_pid=fork();
	if(process_pid==0){
		const char *buffer="this is written by Child Process\n";
		ssize_t size=strlen(buffer);
		ssize_t buffer_size=write(fd, buffer, size);
	}
	else if(process_pid>0){
		const char *buffer="this is written by Parent Process\n";
		ssize_t size=strlen(buffer);
		ssize_t buffer_size=write(fd, buffer, size);
	}
	else{
		printf("fork call not working\n");
		return 0;
	}
	close(fd);
	return 0;
}

