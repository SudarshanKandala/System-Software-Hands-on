#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/wait.h>

int main(){
    pid_t pid;
    pid = fork();
    if(pid == 0){
        printf("Executing background process for creating 5 different files\n");
        execvp("./background_process", NULL);
        printf("exec failed\n");
        exit(1);
    }
    sleep(2);
    char path[25] = "/proc/";
    char str_pid[10];
    snprintf(str_pid, sizeof(str_pid), "%d", pid);
    strcat(path, str_pid);
    strcat(path, "/fd/");
    DIR *dir_stream;
    struct dirent *entry;
    dir_stream = opendir(path);
    if(dir_stream == NULL){
        printf("unable to open Directory /proc\n");
        exit(1);
    }
    printf("Entries in %s\n", path);
    while((entry = readdir(dir_stream)) != NULL){
        printf("%s\n", entry->d_name);
    }
    closedir(dir_stream);
    return 0;
}
