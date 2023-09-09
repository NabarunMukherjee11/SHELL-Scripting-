/*
============================================================================
Name : file105.c
Author : Nabarun Mukherjee
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 9th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
int main(){
	int fd1=creat("myFirstFileFor5", 0666);
	int fd2=creat("mySecondFileFor5", 0666);
	int fd3=creat("myThirdFileFor5", 0666);
	int fd4=creat("myFourthFileFor5", 0666);
	int fd5=creat("myFifthFileFor5", 0666);
	while(1);
	return 0;
}

