// run this code using sudo ./a.out

#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<signal.h>
#include<unistd.h>

int main(){
    pid_t pid = fork();
    if(pid == 0){
        while(1){
            printf("child executing\n");
            sleep(5);
        }
        exit(0);
    }
    int priority = getpriority(PRIO_PROCESS, pid);
    printf("Priority of child process: %d\n", priority);
    printf("Changing priority to higher value\n");
    int success = setpriority(PRIO_PROCESS, pid, -15);
    printf("Updated Priority: %d\n", getpriority(PRIO_PROCESS, pid));
    sleep(5);
    printf("killing child process\n");
    kill(pid, 2);
    return 0;
}
