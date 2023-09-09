/*
============================================================================
Name : file104.c
Author : Nabarun Mukherjee
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also. 
Date: 9th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main() {
	int fd = open("myFileFor4.txt", O_CREAT|O_EXCL, 0666);
	if(fd == -1) {
		printf("Failed");
		return 1;
	}
	printf("File Created Exclusively");

	fd = open("myFileFor4.txt", O_RDWR);
	if(fd == -1) {
		printf("Failed");
		return 1;
	}
	printf("File open in Read Write mode");

	return 0;
}

