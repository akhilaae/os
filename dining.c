#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

sem_t chopstick[5];
void* philosopher(void* n){
    int i=*(int*)n;
    sem_wait(&chopstick[i]);
    printf("philospher %d pickup left\n",i);
    sem_wait(&chopstick[(i+1)%5]);
    printf("philospher %d pickup right\n",i);
    printf("philosopher %d eating\n",i);
    sleep(1);
    printf("p %d drops right\n",i);
    sem_post(&chopstick[(i+1)%5]);
    printf("p %d drops left\n",i);
    sem_post(&chopstick[i]);
    printf("p %d is thinking\n",i);

}
void main(){
    printf("5 philosophers and 5 chopsticks\n");
    int arg[5];
    pthread_t p[5];
    for(int i=0;i<5;i++){
        sem_init(&chopstick[i],0,1);
    }
    for(int i=0;i<5;i++){
        arg[i]=i;
        pthread_create(&p[i],NULL,philosopher,(void*)&arg[i]);
    }
    for(int i=0;i<5;i++){
        pthread_join(p[i],NULL);
    }
}