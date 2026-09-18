#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    if(!fork())
        printf("Process ID of child Process: %d\n", getpid());
    else
        printf("Process ID of parent Process; %d\n", getpid());
    return 0;
}
