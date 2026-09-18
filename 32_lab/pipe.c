#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

int main(){
    int fd[2];
    if(pipe(fd) == -1){
        printf("Pipe failed\n");
        return 1;
    }
    if(fork()){
        close(fd[0]);
        char msg[30] = "Message from Parent";
        write(fd[1], msg, strlen(msg)+1);
        close(fd[1]);
        exit(0);
    }
    close(fd[1]);
    char msg[100];
    ssize_t bytes_read = read(fd[0], msg, sizeof(msg));
    if(bytes_read == -1){
        printf("error reading\n");
        exit(1);
    }
    msg[bytes_read] = '\0';
    printf("Child Received: %s\n", msg);
    return 0;
}
