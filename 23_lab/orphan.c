
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    if(!fork()){
        printf("As the parent process died before child did, it is going to become a Orphan Process\n");
        sleep(5);
        printf("Process pid: %d\nParent PID: %d\n", getpid(), getppid());
        exit(0);
    }
    exit(0);
}
