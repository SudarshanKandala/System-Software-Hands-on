#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main(){
    int fd = open("Ticket_details.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
    for(int train_num = 1; train_num <=3; train_num++){
        int initial_ticket_num = 10;
        char buffer[4];
        sprintf(buffer, "%d", initial_ticket_num);
        char train_number[10];
        sprintf(train_number, "%d", train_num);
        strcat(train_number, " ");
        strcat(train_number, buffer);
        strcat(train_number, "\n");
        lseek(fd, 0, SEEK_END);
        int bytes_written = write(fd, train_number, strlen(train_number));
        if(bytes_written == -1){
            printf("Error Storing initial ticket number\n");
            exit(1);
        }
        char read_buf[100]; 
        lseek(fd, 0, SEEK_SET);
        int bytes_read = read(fd, read_buf, sizeof(read_buf));
        read_buf[bytes_read] = '\0';
        if(bytes_read == -1){
            printf("Error reading initial ticket number\n");
            exit(1);
        }
        printf("Contents of file: \n%s", read_buf);
    }
    close(fd);
    return 0;
}
