/*
============================================================================
Name : file103.c
Author : Nabarun Mukherjee
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call.
Date: 9th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>

int main() {
	int fd = creat("myFileFor3", 0666);
	printf("File discriptor value: %d", fd);
	return 0;
}

