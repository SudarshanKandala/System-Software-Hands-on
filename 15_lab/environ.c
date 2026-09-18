#include<stdio.h>

extern char **environ;

int main(){
    printf("Environment Variables: \n");
    for(int i=0;environ[i]!=NULL;i++){
        printf("%s\n", environ[i]);
    }
    return 0;
}
