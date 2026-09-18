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
    int fd_write = open("my_pipe1", O_WRONLY);
    int fd_read = open("my_pipe2", O_RDONLY);
    char msg[100] = "Hello Sudarshan!\n";
    write(fd_write, msg, strlen(msg)+1);
    char buffer[100];
    read(fd_read, buffer, sizeof(buffer));
    printf("Read from pipe2: %s\n", buffer);
    return 0;
}
