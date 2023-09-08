#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
 
int main(int argc, char *argv[]){
	if(argc!=2){
		printf("input the file to be edited\n");
		return 0;
	}
	char *filename=argv[1];
	int fd=open(filename, O_WRONLY);
	int buffer;
	scanf("%d", &buffer);
	write(fd, &buffer, sizeof(buffer));
	return 0;
}	
	
