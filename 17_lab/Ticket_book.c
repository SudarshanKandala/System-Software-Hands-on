#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main(){
    int fd = open("Ticket_details.txt", O_RDWR, 0644);
    if(fd == -1){
        printf("%s file doesnot exist\n");
        exit(1);
    }
    printf("Initializing Ticket Booking...\n");
    struct flock lock;
    memset(&lock, 0, sizeof(lock));
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();
    int ret = fcntl(fd, F_SETLKW, &lock);
    if(ret < 0){
        printf("Unable to acquire write lock\n");
        exit(1);
    }
    printf("Write Lock Acquired\n");
    char buffer[10];
    int bytes_read = read(fd, buffer, sizeof(buffer));
    if(bytes_read == -1){
        printf("Error reading initial ticket number\n");
        exit(1);
    }
    printf("Booking for Ticket Number: %s\n", buffer);
    printf("Press ENTER to continue...\n");
    if(getchar() != '\n'){
        printf("Aborting Ticket Booking\n");
        return 0;
    }
    lseek(fd, 0, SEEK_SET);
    if(ftruncate(fd, 0) == -1){
        printf("Error truncating file\n");
        exit(1);
    }
    int ticket_number = atoi(buffer);
    ticket_number++;
    sprintf(buffer, "%d", ticket_number);
    int bytes_written = write(fd, buffer, strlen(buffer));
    if(bytes_written == -1){
        printf("Error Storing initial ticket number\n");
        exit(1);
    }
    lock.l_type = F_UNLCK;
    ret = fcntl(fd, F_SETLKW, &lock);
    if(ret == -1){
        printf("Error releasing write lock\n");
        exit(1);
    }
    printf("Write Lock Released\n");
    printf("Ticket Booking Successful\n");
    close(fd);
    return 0;
}

