#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(){
    char path[100];
    scanf("%s", &path);
    while(access(path, F_OK) != 0){
        printf("Please enter the path correctly!\n");
    }
    struct stat file_stat;
    if(stat(path, &file_stat)!=0){
        printf("Error reading stats\n");
        exit(1);
    }
    switch(file_stat.st_mode & S_IFMT){
        case S_IFREG: printf("Regular File\n"); break;
        case S_IFDIR: printf("Directory\n"); break;
        case S_IFLNK: printf("Link file\n"); break;
        case S_IFCHR: printf("Character File\n"); break;
        case S_IFBLK: printf("Block Device\n"); break;
        case S_IFIFO: printf("FIFO file\n"); break;
        case S_IFSOCK: printf("Socket\n"); break;
    }
    return 0;
}
