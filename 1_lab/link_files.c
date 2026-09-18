#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main(){
    int link_type;
    printf("Choose File type to create: 1) Soft Link  2) Hard Link  3) FIFO\n");
    scanf("%d", &link_type);
    if(link_type==1){
        FILE *fptr;
        const char *file_name = "soft.txt";
        const char *soft_link_file = "soft_link.txt";
        struct stat file_stat, soft_file_stat;
        fptr = fopen(file_name, "w");
        if(fptr==NULL){
            printf("Failed to open the file\n");
            return 1;
        }
        fputs("This is an example soft file\n", fptr);
        if(stat(file_name, &file_stat)<0){
            printf("Error getting stat(metadata) of a file%s\n", file_name);
            return 1;
        }
        fclose(fptr);
        int ret = symlink(file_name, soft_link_file);
        if(ret == -1){
            printf("Failed to create a link file\n");
            return 1;
        }
        if(stat(soft_link_file, &soft_file_stat)<0){
            printf("Error getting stat(metadata) of file %s\n", soft_link_file);
        }
        printf("Successfully created softlink file\n");
        printf("Inode of %s file is %d \nInode of %s file is %d",file_name, (unsigned long long)file_stat.st_ino, soft_link_file, (unsigned long long)soft_file_stat.st_ino);
        return 0;
    }
    if(link_type==2){
        FILE *fptr;
        const char *file_name = "hard.txt";
        const char *hard_link_file = "hard_link.txt";
        struct stat file_stat, hard_file_stat;
        fptr = fopen(file_name, "w");
        if(fptr==NULL){
            printf("Failed to open the file\n");
            return 1;
        }
        fputs("This is an example hard file\n", fptr);
        if(stat(file_name, &file_stat)<0){
            printf("Error getting stat(metadata) of a file%s\n", file_name);
            return 1;
        }
        fclose(fptr);
        int ret = link(file_name, hard_link_file);
        if(ret == -1){
            printf("Failed to create a link file\n");
            return 1;
        }
        if(stat(hard_link_file, &hard_file_stat)<0){
            printf("Error getting stat(metadata) of file %s\n", hard_link_file);
        }
        printf("Successfully created softlink file\n");
        printf("Inode of %s file is %d \nInode of %s file is %d",file_name, (unsigned long long)file_stat.st_ino, hard_link_file, (unsigned long long)hard_file_stat.st_ino);
        return 0;
    }
    if(link_type==3){
        const char *file_path = "./my_pipe";
        mode_t mode = S_IFIFO | 0666;
        if(mknod(file_path, mode, 0) == -1){
            printf("Error creating FIFO pipe\n");
            return 1;
        }
        printf("Successfully created FIFO Pipe\n");
        return 0;
    }
    printf("enter correct number\n");
    return 1;
}
