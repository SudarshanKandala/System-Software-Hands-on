#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/select.h>

int main(){
    fd_set read_fds;
    struct timeval timeout;
    int retval;
    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    printf("Waiting for User Input (waiting time 10sec)...\n");
    retval = select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &timeout);
    if(retval == -1){
        printf("select returned error\n");
        exit(1);
    }
    if(retval == 0){
        printf("No Input in 10 sec\n");
        exit(0);
    }
    if(FD_ISSET(STDIN_FILENO, &read_fds)){
        char buffer[100];
        read(STDIN_FILENO, buffer, sizeof(buffer));
        printf("Data Available before timeout: %s", buffer);
    }
    return 0;
}
