#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main(int argc, char *argv[]){
	if(argc!=2){
		printf("give a file to be locked\n");
		return 0;
	}
	struct flock lock;
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=0;
	lock.l_pid=getpid();

	int fd=open(argv[1], O_RDWR| O_CREAT);
	if(fd==0){
		printf("couldnt open file\n");
		return 0;
	}
	printf("Before entering the critical section\n");
	fcntl(fd, F_SETLKW, &lock);
	printf("inside exclusive lock\n");
	char *x="Hello";
	ssize_t wr= write(fd, x, strlen(x));
	if(wr!=-1){
		printf("written");
	}
	getchar();
	lock.l_type=F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	printf("File is unlocked\n");
	close(fd);
	return 0;
}
