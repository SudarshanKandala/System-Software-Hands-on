#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

int main(){
    int pipe1[2];
    int pipe2[2];
    if(pipe(pipe1) == -1){
        printf("Pipe1 failed\n");
        return 1;
    }
    if(pipe(pipe2) == -1){
        printf("Pipe2 failed\n");
        return 1;
    }
    if(fork()){
        close(pipe1[0]);
        close(pipe2[1]);
        char msg_write[30] = "Message from Parent";
        char msg_read[100];
        write(pipe1[1], msg_write, strlen(msg_write)+1);
        ssize_t bytes_read = read(pipe2[0], msg_read, sizeof(msg_read));
        if(bytes_read == -1){
            printf("error reading\n");
            exit(1);
        }
        msg_read[bytes_read] = '\0';
        printf("Parent Received: %s\n", msg_read);
        close(pipe1[1]);
        close(pipe2[0]);
        exit(0);
    }
    close(pipe1[1]);
    close(pipe2[0]);
    char msg_read[100];
    char msg_write[30] = "Message from Child";
    ssize_t bytes_read = read(pipe1[0], msg_read, sizeof(msg_read));
    write(pipe2[1],msg_write, strlen(msg_write)+1);
    if(bytes_read == -1){
        printf("error reading\n");
        exit(1);
    }
    msg_read[bytes_read] = '\0';
    printf("Child Received: %s\n", msg_read);
    close(pipe1[1]);
    close(pipe2[0]);
    return 0;
}
