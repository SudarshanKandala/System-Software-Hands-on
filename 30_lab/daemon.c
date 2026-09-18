#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

int main(){
    if(fork())
        exit(0);
    setsid();
    chdir("/");
    umask(0);
    while(1){
        sleep(3);
        write(1, "Hello\n", 6);
    }
    return 0;
}
