#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(){
    mknod("mknod_pipe", S_IFIFO | 0666, 0);
    return 0;
}
