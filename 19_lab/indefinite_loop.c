#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    printf("Process ID: %d\n", getpid());
    printf("Press ctrl+Z to stop the process and 'ps -o pid' to view the status of the process\n");
    while(1);
    return 0;
}
