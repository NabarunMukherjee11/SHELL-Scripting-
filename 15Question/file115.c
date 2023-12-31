/*
============================================================================
Name : file115.c
Author : Nabarun Mukherjee
Description : Write a program to display the environmental variable of the user (use environ).
Date: 9th Sep, 2023.
============================================================================
*/

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
