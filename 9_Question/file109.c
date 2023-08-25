#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc, char* argv[]){
	if(argc<2){
		printf("Issue with File/n");
		return -1;
	}
	struct stat file_info;
	stat(argv[1], &file_info);
	printf("inode: %ld\n", (long)file_info.st_ino);
	printf("number of hardlinks: %ld\n", (long)file_info.st_nlink);
	printf("User ID: %ld\n", (long)file_info.st_uid);
	printf("Group ID: %ld\n", (long)file_info.st_gid);
	printf("File Size: %ld\n", (long)file_info.st_size);
	printf("Block Size: %ld\n", (long)file_info.st_blksize);
	printf("Number of Blocks: %ld\n", (long)file_info.st_blocks);
	printf("Last Access Time: %ld\n", (long)file_info.st_atime);
	printf("Last Modification Time: %ld\n", (long)file_info.st_mtime);
	printf("Last Time of Status Change: %ld\n", (long)file_info.st_ctime);
	printf("inode: %ld/n", (long)file_info.st_ino);

	return 0;
}

