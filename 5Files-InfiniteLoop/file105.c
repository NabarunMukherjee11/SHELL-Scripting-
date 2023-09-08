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

