#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int fd1[2];
    int fd2[2];
    if(pipe(fd1) == -1){
        printf("Pipe creation Failed\n");
        exit(1);
    }
    if(pipe(fd2) == -1){
        printf("pipe2 creation failed\n");
        exit(1);
    }
    if(!fork()){
        close(1);
        close(fd1[0]);
        int new_fd_write = dup2(fd1[1], 1);
        int ret = system("ls -l");
        close(fd1[1]);
        exit(0);
    }
    close(fd1[1]);
    wait(0);
    if(!fork()){
        close(0);
        close(1);
        close(fd1[1]);
        close(fd2[0]);
        int new_fd_read = dup2(fd1[0], 0);
        int new_fd_write = dup2(fd2[1], 1);
        int ret = system("grep ^d");
        close(fd1[0]);
        close(fd2[1]);
        exit(0);
    }
    close(fd2[1]);
    wait(0);
    if(!fork()){
        close(0);
        close(fd2[1]);
        int new_fd_read = dup2(fd2[0], 0);
        int ret = system("wc");
        close(fd2[0]);
        exit(0);
    }
    wait(0);
    return 0;
}
