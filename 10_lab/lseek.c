#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

int main(){
    int fd = open("Example.txt", O_CREAT | O_RDWR, 0644);
    char buffer[20] = "abcdefghij";
    ssize_t bytes_write = write(fd, buffer, 10);
    if(bytes_write == -1){
        printf("Error writing into file\n");
        exit(1);
    }
    off_t bytes_from_beginning = lseek(fd, 10, SEEK_CUR);
    printf("Current Position of pointer from beginning: %ld bytes\n", (long)bytes_from_beginning);
    bytes_write = write(fd, buffer, 10);
    off_t size_of_file = lseek(fd, 0, SEEK_END);
    printf("Total size of file: %ld bytes\n", (long)size_of_file);
    close(fd);
    return 0;
}
