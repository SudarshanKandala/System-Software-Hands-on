#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main(){
    int fd = open("Ticket_details.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
    int initial_ticket_num = 10;
    char buffer[10];
    sprintf(buffer, "%d", initial_ticket_num);
    int bytes_written = write(fd, buffer, sizeof(buffer));
    if(bytes_written == -1){
        printf("Error Storing initial ticket number\n");
        exit(1);
    }
    int bytes_read = read(fd, buffer, sizeof(buffer));
    if(bytes_read == -1){
        printf("Error reading initial ticket number\n");
        exit(1);
    }
    printf("Initial Ticket Number: %s", buffer);
    close(fd);
    return 0;
}
