#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	pid_t child_pid;
	child_pid=fork();
	if(child_pid==0){
		printf("The process id of Child is: %d\n", child_pid);
	}
	else if(child_pid>0){
		printf("The process id of Parent is: %d\n", child_pid);
	}
	else{
		printf("Fork Failed\n");
		return 1;
	}
	return 0;
}
