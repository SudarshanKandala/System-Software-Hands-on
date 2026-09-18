#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(){
    int fd = open("Example.txt", O_CREAT | O_RDWR | O_APPEND | O_TRUNC, 0644);
    if(fd == -1){
        printf("Error opening file\n");
        exit(1);
    }
    printf("O_CREAT: %d\nO_RDWR: %d\nO_RDONLY: %d\nO_WRONLY: %d\nO_TRUNC: %d\nO_APPEND: %d\n", O_CREAT, O_RDWR, O_RDONLY, O_WRONLY, O_TRUNC, O_APPEND);
    int opening_modes = fcntl(fd, F_GETFL);
    printf("%d\n", opening_modes);
    // if(opening_modes & O_CREAT)
    //     printf("O_CREAT is enabled\n");
    if(opening_modes & O_RDWR)
        printf("O_RDWR is enabled\n");
    if(opening_modes & O_RDONLY)
        printf("O_RDONLY is enabled\n");
    if(opening_modes & O_WRONLY)
        printf("O_WRONLY is enabled\n");
    // if(opening_modes & O_TRUNC)
    //     printf("O_TRUNC is enabled\n");
    if(opening_modes & O_APPEND)
        printf("O_APPEND is enabled\n");
    return 0;
}
