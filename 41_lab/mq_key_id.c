#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys.msg.h>

int main(){
    key_t key;
    int msgid;
    key = ftok(".", 'A');
    if(key == -1){
        printf("ftok failed\n");
        exit(1);
    }
    msgid = msgget(key, IPC_CREAT | 0666);
    if(msgid == -1){
        printf("msgget failed\n");
        exit(1);
    }
    printf("Key: 0x%08x\n", key);
    printf("Message Queue ID: %d\n", msgid);
    return 0;
}
