#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
 void main(){
    int fd=open("a.txt",O_RDONLY,O_CREAT);
    char str[100];
    int len=read(fd,str,10);
    str[len]='\0';
    printf("%s",str);
    int c=close(fd);
    if(c<0){
        printf("closing failed");
    }
    else{
        printf("closed");
    }
 }