#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

int main(){
    int fd = open("./Existing_file.txt", O_RDWR);
    char buffer[100];
    memset(buffer, 0, sizeof(buffer));
    ssize_t bytes_read;
    while((bytes_read = read(fd, buffer, sizeof(buffer))) > 0){
        ssize_t bytes_write = write(1, buffer, bytes_read);
        if(bytes_write == -1){
            perror("error writing into stdout\n");
            close(fd);
            exit(1);
        }
    }
    if(bytes_read == -1){
        perror("error reading from stdin\n");
        close(fd);
        exit(1);
    }
    close(fd);
    int fd1 = open("Example.txt", O_WRONLY | O_CREAT | O_EXCL, 0644);
    if(fd1 == -1){
        printf("File may already exists or error creating file\n");
        return 1;
    }
    printf("Created and opened the file with fd: %d\n", fd1);
    return 0;
}
