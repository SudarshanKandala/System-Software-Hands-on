#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main(){
    ssize_t read_bytes;
    char buffer[100];
    printf("start entering your content and type 'exit' to terminate the process: \n");
    while((read_bytes = read(0, buffer, sizeof(buffer))) > 0){
        ssize_t write_bytes = write(1, buffer, read_bytes);
        if(write_bytes == -1){
            printf("error writing in stdout\n");
            exit(1);
        }
        if(strcmp(buffer, "exit\n") == 0)
            exit(0);
    }
    if(read_bytes == -1){
        printf("Error reading stdin\n");
        exit(1);
    }
    return 0;
}
