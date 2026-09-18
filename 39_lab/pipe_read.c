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
    int fd = open("my_pipe", O_RDONLY);
    close(0);
    int new_fd = dup2(fd, 0);
    fd_set read_set;
    FD_ZERO(&read_set);
    FD_SET(fd, &read_set);
    struct timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    printf("Waiting for 10sec for data to arrive\n");
    int ready = select(fd+1, &read_set, NULL, NULL, &timeout);
    if(ready == -1){
        printf("Error in select()\n");
        exit(1);
    }
    else if(ready == 0){
        printf("No data in 10 seconds\n");
        exit(0);
    }
    else{
        if(FD_ISSET(fd, &read_set)){
            char buffer[100];
            ssize_t read_bytes = read(fd, buffer, sizeof(buffer));
            if(read_bytes == 0)
                printf("No data arrived\n");
            else{
                buffer[read_bytes] = '\0';
                printf("Data received: %s", buffer);
            }
        }
    }
    return 0;
}
