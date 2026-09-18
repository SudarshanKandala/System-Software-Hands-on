#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

int main(){
    if(mkfifo("./mkfifo_pipe", 0666) == -1){
        if(errno == EEXIST)
            printf("Named Pipe already exists\n");
        else
            printf("Error creating pipe\n");
    }
    return 0;
}
