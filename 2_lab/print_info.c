#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<signal.h>

int main(){
    pid_t pid = fork();
    if(pid<0){
        printf("Fork Failed\n");
        exit(1);
    }
    if(pid==0){
        char *args[] = {"./indefinite_program", NULL};
        execvp(args[0], args);
        printf("exec failed\n");
        exit(1);
    }
    printf("A background Process has been started with pid: %d\n", pid);
    printf("Traversing /proc directory to find the process Information\n");
    char dir[30] = "/proc/";
    char str_pid[20];
    snprintf(str_pid, sizeof(str_pid), "%d", pid);
    strcat(str_pid, "/status");
    strcat(dir, str_pid);
    FILE *fptr;
    fptr = fopen(dir, "r");
    char data[50];
    printf("information regarding process present in /proc/%d/status: \n", pid);
    while(fgets(data, 50, fptr) != NULL){
        printf("%s", data);
    }
    printf("Press enter to kill the process %d\n", pid);
    char ch;
    if(getchar() == '\n'){
        if(kill(pid, SIGTERM) == 0){
            printf("process %d Killed Successfully\n", pid);
        }
        else{
            printf("Failed killing process\n");
        }
    }
    return 0;
}
