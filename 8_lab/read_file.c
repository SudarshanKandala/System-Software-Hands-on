#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main(){
    int fd = open("source.txt", O_RDONLY);
    ssize_t bytes_read;
    char buffer[100];
    while((bytes_read = read(fd, buffer, sizeof(buffer))) > 0){
        ssize_t write_bytes = write(1, buffer, bytes_read);
        if(write_bytes == -1){
            printf("error printing\n");
            exit(1);
        }
    }
    if(bytes_read == -1){
        printf("error reading\n");
        exit(1);
    }
    return 0;
}
