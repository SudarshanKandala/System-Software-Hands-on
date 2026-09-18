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
    int fd = open("my_pipe", O_WRONLY);
    char msg[100] = "Hello from write end\n";
    write(fd, msg, strlen(msg)+1);
    return 0;
}
