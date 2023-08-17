#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
void main(){
    int fd=open("a.txt",O_WRONLY,O_CREAT);
    char buff[100];
    printf("string : ");
    scanf("%s",buff);
    int len=write(fd,buff,strlen(buff));
    printf("data written %d letters\n",len);
    close(fd);
    int fd2=open("a.txt",O_RDONLY);
    char str[100];
    int len2=read(fd2,str,6);
    str[len2]='\0';
    printf("string : %s",str);
    close(fd);
}