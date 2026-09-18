#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(){
    int i=0;
    int fd[5];
    while(true){
        if(i<5){
            char file_name[20] = "Example_";
            char file_no[3];
            snprintf(file_no, sizeof(file_no), "%d", i+1);
            strcat(file_name, file_no);
            strcat(file_name, ".txt");
            fd[i] = open(file_name, O_WRONLY| O_CREAT | O_EXCL, 0644);
            if(fd[i] == -1){
                printf("Error creating File %s\n", file_name);
            }
            else{
                printf("File %s created successfully\n", file_name);
            }
            i++;
        }
    }
    return 0;
}
