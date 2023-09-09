/*
============================================================================
Name : file117.c
Author : Nabarun Mukherjee
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.

Date: 9th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
 
int main(int argc, char *argv[]){
	if(argc!=2){
		printf("input the file to be edited\n");
		return 0;
	}
	char *filename=argv[1];
	int fd=open(filename, O_WRONLY);
	int buffer;
	scanf("%d", &buffer);
	write(fd, &buffer, sizeof(buffer));
	return 0;
}	
	
