#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <fcntl.h>

int main(){
    mqd_t mq;
    struct mq_attr attr;
    unsigned int priority;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 100;
    attr.mq_curmsgs = 0;

    mq = mq_open("/msg_queue", O_CREAT | O_RDWR, 0644, &attr);
    if(mq == (mqd_t)-1){
        printf("mq open failed\n");
        exit(1);
    }
    char msg_send[100] = "Hello from sender\n";
    if(mq_send(mq, msg_send, strlen(msg_send)+1, 10) == -1){
        printf("mq_send failed\n");
        mq_close(mq);
        exit(1);
    }
    char buffer[100];
    if(mq_receive(mq, buffer, 100, &priority) == -1){
        printf("mq_receive failed\n");
        mq_close(mq);
        exit(1);
    }
    printf("Message Received: %s (Priority level: %u)\n", buffer, priority);
    mq_close(mq);
    mq_unlink("/msg_queue");
    return 0;
}


