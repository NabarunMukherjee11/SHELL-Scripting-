#include<unistd.h>
#include<stdio.h>

#define buffer_size 1024 // defining buffer size in bytes
int main(){
	char Buffer[buffer_size];
	ssize_t bytes_read, bytes_write;
	
	while((bytes_read=read(STDIN_FILENO, Buffer, buffer_size)) > 0){
		bytes_write=write(STDOUT_FILENO, Buffer, bytes_read);
		if(bytes_write!=bytes_read){
		    perror("Error found");
		    return 1;
		}
            }
        if(bytes_read==-1){
		perror("Error found");
		return 1;
	}
	
	return 0;
}
