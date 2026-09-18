#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    if(!fork()){
        printf("Child Process executing execl\n");
        execl("/usr/bin/ls", "-Rl", NULL);
        printf("execl failed\n");
        exit(1);
    }
    if(!fork()){
        printf("Child Process executing execlp\n");
        execlp("ls", "-Rl", NULL);
        printf("execlp failed\n");
        exit(1);
    }
    if(!fork()){
        printf("Child Process executing execv\n");
        char *param[] = {"-Rl", NULL};
        execv("/usr/bin/ls", param);
        printf("execv failed\n");
        exit(1);
    }
    if(!fork()){
        printf("Child Process executing execvp\n");
        char *param[] = {"-Rl", NULL};
        execvp("ls", param);
        printf("execvp failed\n");
        exit(1);
    }
    if(!fork()){
        printf("Child Process executing execlp\n");
        char *environ[] = {"PATH=/bin/ls", NULL};
        execle("/usr/bin/ls", "-Rl",NULL, environ);
        printf("execle failed\n");
        exit(1);
    }
    sleep(3);
    return 0;
}
