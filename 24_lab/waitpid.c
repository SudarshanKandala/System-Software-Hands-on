#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t pid[3];
    pid[0] = fork();
    if(pid[0] == 0){
        pid[0] = getpid();
        sleep(2);
        exit(0);
    }
    pid[1] = fork();
    if(pid[1] == 0){
        pid[1] = getpid();
        sleep(5);
        exit(0);
    }
    pid[2] = fork();
    if(pid[2] == 0){
        pid[2] = getpid();
        sleep(10);
        exit(0);
    }
    int status;
    pid_t p = waitpid(pid[1], &status, 0);
    printf("Waitpid returned this pid: %d\n", p);
    if(WIFEXITED(status)){
        printf("Child Exited with exit status: %d\n", WEXITSTATUS(status));
    }
    return 0;
}
