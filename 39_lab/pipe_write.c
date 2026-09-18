#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/select.h>

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
    close(1);
    int new_fd = dup2(fd, 1);
    char buffer[100];
    ssize_t byres_read = read(0, buffer, sizeof(buffer)-1);
    ssize_t write_bytes = write(fd, buffer, strlen(buffer)+1);
    if(write_bytes<0)
        printf("write failed\n");
    return 0;
}
