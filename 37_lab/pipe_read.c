#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int main(){
    int ret = mkfifo("./my_pipe", 0666);
    if(ret == -1){
        if(errno == EEXIST)
            printf("Pipe already exists\n");
        else{
            printf("pipe creation failed\n");
            exit(1);
        }
    }
    int fd = open("my_pipe", O_RDONLY);
    char msg[100];
    read(fd, msg, sizeof(msg));
    printf("Message Received at read end: %s", msg);
    return 0;
}
