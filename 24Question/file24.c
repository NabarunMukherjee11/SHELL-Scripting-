#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<sys/types.h>

int main(){
	if(!fork()){
		printf("the parent id of the child before orphan is %d\n", getppid());
		sleep(10);
                printf("the parent id of child after becoming orphan is %d\n", getppid());
		return 0;
	}
	else{
		printf("the parent process with pid %d\n", getpid());
		return 0;
	}
	return 0;
}

