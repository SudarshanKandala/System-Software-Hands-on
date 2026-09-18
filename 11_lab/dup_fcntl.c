#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main(){
    int fd = open("Example.txt", O_CREAT | O_RDWR | O_APPEND | O_TRUNC, 0644);
    if(fd == -1){
        printf("Error opening the file\n");
        exit(1);
    }
    char *initial_buffer = "This is the initial conent before duplicating fd\n";
    ssize_t write_bytes = write(fd, initial_buffer, strlen(initial_buffer));
    if(write_bytes == -1){
        printf("Error writing initial content\n");
        exit(1);
    }
    int fd1 = dup(fd);
    char *first_append = "Content after 1st duplication of fd using dup()\n";
    write_bytes = write(fd1, first_append, strlen(first_append));
    if(write_bytes == -1){
        printf("Error writing initial content\n");
        exit(1);
    }
    int fd2 = dup2(fd, 10);
    char *second_append = "Content after 2nd duplication of fd using dup2()\n";
    write_bytes = write(fd2, second_append, strlen(second_append));
    if(write_bytes == -1){
        printf("Error writing initial content\n");
        exit(1);
    }
    int fd3 = fcntl(fd, F_DUPFD, 0);
    char *third_append = "Content after 3rd duplication of fd using fcntl()\n";
    write_bytes = write(fd3, third_append, strlen(third_append));
    if(write_bytes == -1){
        printf("Error writing initial content\n");
        exit(1);
    }
    printf("All the file descriptors that's created by open(), dup(), dup2(), fcntl() for Example.txt are %d, %d, %d, %d\n", fd, fd1, fd2, fd3);
    return 0;
}
