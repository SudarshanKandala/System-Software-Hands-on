#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>
#include<time.h>

int main(){
    ssize_t bytes_read;
    char file_path[128];
    printf("Enter the path of file which details are needed: ");
    scanf("%s", file_path);
    if(access(file_path, F_OK) != 0){
        if(errno == ENOENT)
            printf("The Path is valid but the file doesnot exist\n");
        if(errno == EACCES)
            printf("Path is correct But No permission to access\n");
        else 
            printf("Path Entered is wrong");
        exit(1);
    }
    struct stat file_stat;
    if(stat(file_path, &file_stat) < 0){
        printf("Error retrieving metadata\n");
        exit(1);
    }
    printf("\nFile Information: \n");
    printf("a. Inode Number: %ld\n", (long)file_stat.st_ino);
    printf("b. Hard Links: %ld\n", (long)file_stat.st_nlink);
    printf("c. Owner UID: %u\n", file_stat.st_uid);
    printf("d. Group GID: %u\n", file_stat.st_gid);
    printf("e. Size of file: %ld bytes\n", (long)file_stat.st_size);
    printf("f. Block size: %ld bytes\n", (long)file_stat.st_blksize);
    printf("g. Number of blocks: %ld\n", (long)file_stat.st_blocks);
    printf("h. Last Accessed:   %s", ctime(&file_stat.st_atime));
    printf("i. Last Modified:   %s", ctime(&file_stat.st_mtime));
    printf("j. Last Changed:    %s", ctime(&file_stat.st_ctime));
    return 0;
}
