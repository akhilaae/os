#include <stdio.h>
#include <unistd.h>
void main(){
    int parent=getpid();
    int pid;
    pid=fork();
    if(pid>0){
        printf("parent : %d, child :%d   %d",parent,pid,getpid());
    }
}