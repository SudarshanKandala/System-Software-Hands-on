#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

int main(){
    int msqid;
    msqid = msgget(IPC_PRIVATE, 0666| IPC_CREAT);
    struct msqid_ds buf;
    if(msgctl(msqid, IPC_STAT, &buf) == -1){
        exit(1);
    }
    printf("Access Permission : %o\n", buf.msg_perm.mode & 0777);
    printf("UID: %u\n", buf.msg_perm.uid);
    printf("GID: %u\n", buf.msg_perm.gid);
    printf("Last msgsnd time: %s", ctime(&buf.msg_stime));
    printf("Last msgrcv time: %s", ctime(&buf.msg_rtime));
    printf("Last change time: %s", ctime(&buf.msg_ctime));
    printf("Current queue size: %lu bytes\n", buf.__msg_cbytes);
    printf("Number of messages: %lu\n", buf.msg_qnum);
    printf("Maximum queue size: %lu bytes\n", buf.msg_qbytes);
    printf("PID of last msgsnd: %d\n", buf.msg_lspid);
    printf("PID of last msgrcv: %d\n", buf.msg_lrpid);
    return 0;
}
