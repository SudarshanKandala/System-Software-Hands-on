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
    int train_num;
    printf("Enter the train number that you wanted to book: ");
    scanf("%d", &train_num);
    printf("Initializing Ticket Booking...\n");

    lseek(fd, 0, SEEK_SET);
    int target_line = train_num;
    off_t line_start = 0;
    off_t line_end = 0;
    int current_line = 1;
    char ch;
    while(read(fd, &ch, 1) == 1){
        if(ch == '\n'){
            if(current_line == target_line){
                line_end = lseek(fd, 0, SEEK_CUR);
                break;
            }
            current_line++;
            line_start = lseek(fd, 0, SEEK_CUR);
        }
    }

    struct flock lock;
    memset(&lock, 0, sizeof(lock));
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = line_start;
    lock.l_len = line_end - line_start;
    lock.l_pid = getpid();
    int ret = fcntl(fd, F_SETLKW, &lock);
    if(ret < 0){
        printf("Unable to acquire write lock\n");
        exit(1);
    }
    printf("Write Lock Acquired for %d train\n", current_line);
    char buffer[10];
    lseek(fd, line_start, SEEK_SET);
    int bytes_read = read(fd, buffer, line_end - line_start);
    printf("buffer: %s\n", buffer);
    if(bytes_read == -1){
        printf("Error reading initial ticket number\n");
        exit(1);
    }
    int ticket_number = 0;
    ticket_number = (buffer[2]-'0')*10+(buffer[3]-'0');
    printf("Booking for Ticket Number: %d\n", ticket_number);
    while(getchar()!='\n');
    printf("Press ENTER to continue...\n");
    if(getchar() != '\n'){
        printf("Aborting Ticket Booking\n");
        return 0;
    }
    lseek(fd, line_start, SEEK_SET);
    ticket_number++;
    buffer[2] = ticket_number / 10 + '0';
    buffer[3] = ticket_number % 10 + '0';
    // sprintf(buffer, "%d", ticket_number);
    int bytes_written = write(fd, buffer, bytes_read);
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

