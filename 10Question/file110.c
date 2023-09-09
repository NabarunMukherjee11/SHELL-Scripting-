/*
============================================================================
Name : file110.c
Author : Nabarun Mukherjee
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
 a. check the return value of lseek
 b. open the file with od and check the empty spaces in between the data
Date: 9th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

int main(int argc, char* argv[]){
	if(argc!=2){
		printf("could not get the input correctly");
		return -1;
	}

	char *filename=argv[1];
	int fd=open(filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if(fd==-1){
		printf("File not open correctly");
		return 1;
	}
	const char buffer[]="0123456789";
	ssize_t bytes_written=write(fd, buffer, 10);
	if(bytes_written==-1){
		printf("Not written properly");
		close(fd);
		return 1;
	}
	int newoffset=lseek(fd, 10, SEEK_CUR);
	if(newoffset==-1){
		printf("Error with the lseek function");
		close(fd);
		return 1;
	}

	const char buffer2[]="abchefghijkl";
	ssize_t bytes_written_again=write(fd, buffer2, 10);

	if(bytes_written_again==-1){
		printf("Error while writing the second time");
		close(fd);
		return 1;
	}

	close(fd);
	return 0;
}


