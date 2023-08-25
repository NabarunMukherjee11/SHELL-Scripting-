#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char* argv[]){
	if(argc!=2){
		printf("Please provide inputs correctly\n");
		return 1;
	}
	char *filename=argv[1];

	int fd=open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if(fd==-1){
		printf("File Descriptor showing error\n");
		return 1;
	}

	int dup_fd=dup(fd);
	if(dup_fd==-1){
		printf("The DUP() system call didnt work\n");
		close(fd);
		return 1;
	}

	int dup2_fd=dup2(fd,5);
	if(dup_fd==-1){
		printf("The DUP2() system call didnt work \n");
		close(fd);
		close(dup_fd);
		return 1;
	}

	int fcntl_fd=fcntl(fd, F_DUPFD, 0);
	if(fcntl_fd==-1){
		printf("The FCNTL() system call didnt work \n");
		close(fd);
		close(dup_fd);
		close(dup2_fd);
		return 1;
	}

	const char DUP_BUFFER[]="This is the sentence append with the help of DUP() system call\n";
	const char DUP2_BUFFER[]="This is the sentence append with the help of DUP2() system call\n";
	const char FCNTL_BUFFER[]="This is the sentence append with the help of FCNTL() system call\n";

	ssize_t buffer1=write(dup_fd, DUP_BUFFER, strlen(DUP_BUFFER));
	if(buffer1==-1){
		printf("writing failed for DUP()\n");
	}

	buffer1=write(dup2_fd, DUP2_BUFFER, strlen(DUP2_BUFFER));
	if(buffer1==-1){
                printf("writing failed for DUP2()\n");
        }
        
	buffer1=write(fcntl_fd, FCNTL_BUFFER, strlen(FCNTL_BUFFER));
	if(buffer1==-1){
                printf("writing failed for DUP()\n");
        }

	close(fd);
	close(dup_fd);
	close(dup2_fd);
	close(fcntl_fd);
	return 0;
}
