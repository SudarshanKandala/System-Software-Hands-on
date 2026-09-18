#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(){
    int fd_read = open("source.txt", O_RDONLY);
    int fd_write = open("Destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(fd_read == -1){
        printf("Error opening file\n");
        exit(1);
    }
    ssize_t bytes_read;
    char buffer[10];
    while((bytes_read = read(fd_read, buffer, sizeof(buffer))) > 0){
        ssize_t written_bytes = write(fd_write, buffer, bytes_read);
        if(written_bytes == -1){
            printf("Error writing into destination\n");
            exit(1);
        }
    } 
    if(bytes_read == -1){
        printf("Error reading the source\n");
        exit(1);
    }
    return 0;
}
