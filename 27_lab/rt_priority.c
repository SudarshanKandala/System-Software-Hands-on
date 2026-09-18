#include<stdio.h>
#include<sched.h>

int main(){
    printf("Maximum Priority Number of Real Time Process: %d\n", sched_get_priority_max(SCHED_FIFO));
    printf("Minimum Priority Number of Real Time Process: %d\n", sched_get_priority_min(SCHED_FIFO));
    return 0;
}
