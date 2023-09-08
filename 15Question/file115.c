#include<stdio.h> 
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
extern char **environ; //Environ variable is declared

int main(){
	char **env=environ;
	for(int i=0; env[i]!=NULL; i++){
		if(strncmp(env[i],"USER", 4)==0){
			printf("%s\n", env[i]);
		}
	}
	return 0;
}
