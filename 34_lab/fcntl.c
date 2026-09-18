#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
    int fd[2];
    if(pipe(fd) == -1){
        printf("Pipe creation Failed\n");
        exit(1);
    }
    if(!fork()){
        close(1);
        close(fd[0]);
        int new_fd = fcntl(fd[1], F_DUPFD, 1);
        int ret = system("ls -l");
        close(fd[1]);
        exit(0);
    }
    else{
        close(0);
        close(fd[1]);
        int new_fd = fcntl(fd[0], F_DUPFD, 0);
        int ret = system("wc");
        close(fd[1]);
        exit(0);
    }
}
