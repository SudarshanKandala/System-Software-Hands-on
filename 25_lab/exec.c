#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    if(!fork()){
        printf("Child Process is executing another executable file\n");
        char *param[] = {"Sudarshan", NULL};
        execvp("./print", param);
        printf("Exec failed\n");
        exit(1);
    }
    return 0;
}
