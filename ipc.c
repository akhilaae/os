#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
void main(){
    key_t key=ftok("shmfile",43);
    int id=shmget(key,1024,0666|IPC_CREAT);
    void* shared_memory=shmat(id,NULL,0);
    char buff[100];
    printf("Enter data to write : ");
    scanf("%s",buff);
    strcpy(shared_memory,buff);
    printf("data written is : %s",(char*)shared_memory);
    shmdt(shared_memory);
}
