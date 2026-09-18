#include<stdio.h>
#include<stdlib.h>
#include<sched.h>
#include<unistd.h>

int main(){
    int policy = sched_getscheduler(0);
    if(policy == -1){
        printf("sched_getscheduler failed\n");
        return 1;
    }
    switch(policy){
        case SCHED_OTHER:
            printf("Policy: SCHED_OTHER\n");
            break;
        case SCHED_RR:
            printf("Policy: SCHED_RR\n");
            break;
        case SCHED_FIFO:
            printf("Policy: SCHED_FIFO\n");
            break;
        default:
            printf("Unknown Policy\n");
    }

    struct sched_param param;
    param.sched_priority = 50;
    int ret = sched_setscheduler(0, SCHED_RR, &param);
    if(ret != 0){
        printf("changing priority failed\n");
        exit(1);
    }
    printf("policy changed successfully\n");
    return 0;
}
