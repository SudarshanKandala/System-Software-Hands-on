#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(){
    if(!fork()){
        printf("Child Process with PID: %d\n", getpid());
        int fd = open("Example.txt", O_RDWR | O_CREAT, 0644);
        char buffer[100] = "This is written by child Process";
        ssize_t bytes_written = write(fd, buffer, strlen(buffer));
        if(bytes_written < 0){
            printf("Error writing into file: %s\n", "Example.txt");
            exit(1);
        }
        lseek(fd, 0, SEEK_SET);
        ssize_t bytes_read = read(fd, buffer, sizeof(buffer)-1);
        if(bytes_read < 0){
            printf("Error reading from file: %s\n", "Example.txt");
            exit(1);
        }
        buffer[bytes_read] = '\0';
        printf("The content Present in File: %s\n", buffer);
        return 0;
    }

    printf("Parent Process with PID: %d\n", getpid());
    int fd = open("Example.txt", O_RDWR | O_CREAT, 0644);
    char buffer[100] = "This is written by Parent Process";
    ssize_t bytes_written = write(fd, buffer, strlen(buffer));
    if(bytes_written < 0){
        printf("Error writing into file: %s\n", "Example.txt");
        exit(1);
    }
    lseek(fd, 0, SEEK_SET);
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer)-1);
    if(bytes_read < 0){
        printf("Error reading from file: %s\n", "Example.txt");
        exit(1);
    }
    buffer[bytes_read] = '\0';
    printf("The content Present in File: %s\n", buffer);
    return 0;
}
