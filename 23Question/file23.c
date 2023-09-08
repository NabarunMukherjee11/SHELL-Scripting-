#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	if(!fork()){
		printf("the child process PID is %d\n", getpid());
	}
	else{	
		printf("the parent process PID is %d\n", getpid());
		sleep(10);
		printf("parent out of sleep");
		int child_id=wait(0);
		printf("Zombie id %d\n", child_id);
	}
	return 0;
}
