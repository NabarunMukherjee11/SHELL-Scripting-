/*
============================================================================
Name : file117b.c
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
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[]){
	if(argc!=2){
		printf("give the filename to open");
		return 0;
	}
	int fd=open(argv[1], O_RDWR);
	if(fd==-1){
		printf("File Descriptor not open");
		return 0;
	}
	int number;
	struct flock lock;
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=0;
	lock.l_pid=getpid();
	fcntl(fd, F_SETLKW, &lock);
	printf("inside the critical section");
	ssize_t buffersize=read(fd, &number, sizeof(number));
	printf("%d\n", number);
	number += 1;
	write(fd, &number, sizeof(number));
	printf("%d\n", number);
	lock.l_type=F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	close(fd);
	return 0;
}
