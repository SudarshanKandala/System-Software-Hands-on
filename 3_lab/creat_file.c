#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int fd = creat("Example.txt", S_IRUSR | S_IWUSR);
    if(fd == -1){
        perror("error creating file\n");
        exit(1);
    }
    printf("File Descriptor of file created: %d\n", fd);
    close(fd);
    return 0;
}
