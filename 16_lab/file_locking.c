#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(){
    const char *filename = "read_lock.txt";
    int fd = open(filename, O_CREAT | O_RDWR , 0644);
    if(fd < 0){
        printf("Error opening %s\n", filename);
        exit(1);
    }
    struct flock lock;
    memset(&lock, 0, sizeof(lock));
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();
    int ret = fcntl(fd, F_SETLK, &lock);
    if(ret < 0){
        printf("Error acquiring lock\n");
        exit(1);
    }
    printf("Read Lock Acquired Successfully\n");
    lock.l_type = F_UNLCK;
    ret = fcntl(fd, F_SETLK, &lock);
    if(ret < 0){
        printf("Unlocking failed\n");
        exit(1);
    }
    printf("Read Lock released Successfully\n");
    lock.l_type = F_WRLCK;
    ret = fcntl(fd, F_SETLK, &lock);
    if(ret < 0){
        printf("Error acquiring write lock\n");
        exit(1);
    }
    printf("Write lock Acquired Successfully\n");
    lock.l_type = F_UNLCK;
    ret = fcntl(fd, F_SETLK, &lock);
    if(ret < 0){
        printf("Error realasing Write lock\n");
        exit(1);
    }
    printf("Write lock released Successfully\n");
    close(fd);
    return 0;
}

