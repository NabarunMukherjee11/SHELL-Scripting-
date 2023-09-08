#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[]){
	if(argc!=2){
		printf("Give proper arguments");
		return 1;
	}
	
	char *filename=argv[1];
	int fd=open(filename, O_RDONLY);
	if(fd==-1){
		printf("File Descriptor not working\n");
		return 1;
	}

	int i=0;
	char c;
	char  buff[1000];

	while(1){
		int b=read(fd, &c, 1);
		if(b!=0 && c=='\n'){
			buff[i++]=c;
			buff[i++]='\0';
		}

		else if(b!=0){
			buff[i++]=c;
			continue;
		}
		write(1, &buff, i);
		i=0;
		if(b==0) break;
	}
	close(fd);
	return 1;
}
	

