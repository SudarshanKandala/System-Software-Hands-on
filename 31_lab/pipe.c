#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){
    int fd[2];
    if(pipe(fd) == -1){
        printf("pipe creation failed\n");
        exit(1);
    }
    char buf[100] = "Hello";
    write(fd[1], buf, strlen(buf)+1);
    char buf1[100];
    read(fd[0], buf1, sizeof(buf1));
    printf("Read from pipe: %s\n", buf1);
    return 0;
}
