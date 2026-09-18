#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int main(){
    int ret = mkfifo("./my_pipe1", 0666);
    if(ret == -1){
        if(errno == EEXIST)
            printf("Pipe already exists\n");
        else{
            printf("pipe creation failed\n");
            exit(1);
        }
    }
    ret = mkfifo("./my_pipe2", 0666);
    if(ret == -1){
        if(errno == EEXIST)
            printf("Pipe already exists\n");
        else{
            printf("pipe creation failed\n");
            exit(1);
        }
    }
    int fd_read = open("my_pipe1", O_RDONLY);
    int fd_write = open("my_pipe2", O_WRONLY);
    char msg[100];
    read(fd_read, msg, sizeof(msg));
    printf("Read at Pipe1: %s", msg);
    char msg_send[100] = "Hi Sudarshan!";
    write(fd_write, msg_send, strlen(msg_send)+1);
    return 0;
}
