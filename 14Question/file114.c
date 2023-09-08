#include<unistd.h> 
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc, char *argv[]){
	if(argc!=2){
		printf("No arguements");
		return 0;
	}
	char *file=argv[1];
	struct stat st;

	stat(file, &st);

	switch(st.st_mode & S_IFMT){
		case S_IFREG: printf("the file is regular type\n"); break;
		case S_IFIFO: printf("the file is FIFO type\n"); break;
		case S_IFLNK: printf("the file is SYMBOLIC LINK type\n"); break;
		case S_IFDIR: printf("the file is DIRECTORY type\n"); break;
		case S_IFSOCK: printf("the file is SOCKET type\n"); break;
		case S_IFCHR: printf("the file is CHARACTER SPECIAL FILE type\n"); break;
		case S_IFBLK: printf("the file is BLOCK SPECIAL FILE type\n"); break;
		default: printf("the file is UNKNOWN type\n"); break;
	}

	return 0;
}
