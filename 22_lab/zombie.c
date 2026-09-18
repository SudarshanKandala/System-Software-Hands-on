#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    if(!fork()){
        printf("This is the child Process going to be in zombie state as parent never reads the exit state of this child\n");
        exit(0);
    }
    sleep(60);
    return 0;
}
