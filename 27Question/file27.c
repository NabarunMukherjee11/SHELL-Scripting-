#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	printf("Choose \n Press 1 for execl() \n Press 2 for execlp() \n Press 3 for execle() \n Press 4 for execv \n Press 5 for execvl \n");
	int x;
	scanf("%d", &x);
	switch(x){
		case (1):
			printf("Using execl() for ls -Rl\n");
			execl("/bin/ls" , "ls", "-Rl",NULL);
			break;
		case(2):
			printf("Using execlp() for ls -Rl\n");
			execlp("ls", "ls", "-Rl", NULL);
			break;
		case(3):
			printf("\nUsing execle() for ls -Rl\n");
			char *env[]={NULL};
			execle("/bin/ls", "ls", "-Rl", NULL, env);
			break;
		case(4):
			printf("\nUsing execv() for ls -Rl\n");
			char *args[]={"ls", "-Rl", NULL};
			execv("/bin/ls", args);
			break;
		case (5):
			printf("\nUsing execvp() for ls -Rl\n");
                        execvp("ls", args);
			break;
	}
	return 0;
}

