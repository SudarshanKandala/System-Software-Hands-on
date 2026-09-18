#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/resource.h>

int main(){
    struct rlimit limit;
    int fd[2];
    long int pipe_size;
    if(getrlimit(RLIMIT_NOFILE, &limit) == 0){
        printf("Current Maximum Open Files(Soft Limit): %ld\n", (long)limit.rlim_cur);
        printf("Maximum Open Files possible(Hard Limit): %ld\n", (long)limit.rlim_max);
    }
    else {
        printf("error getting info\n");
        exit(1);
    }
    if(pipe(fd) == -1){
        printf("Error creating pipe\n");
        exit(1);
    }
    pipe_size = fcntl(fd[0], F_GETPIPE_SZ);
    if(pipe_size != -1){
        printf("Default Pipe size(Circular Buffer): %.2f KB\n", (double)pipe_size/1024.0);
    }
    close(fd[0]);
    close(fd[1]);
    return 0;
}
