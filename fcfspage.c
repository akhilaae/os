#include <stdio.h>
int max,len,frame[100],seq[100],count,f=-1,r=-1;
int search(int x){
    for(int i=0;i<max;i++){
        if(x==frame[i]){
            return 1;
        }
    }
    return 0;
}
int number(){
    int size=0;
    for(int i=0;i<max;i++){
        if(frame[i]!=-1){
            size++;
        }
    }
    return size;
}
void push(int x){
    if(f==-1 && r==-1){
        f=r=0;
    }
    else{
        r=(r+1)%max;
    }
    frame[r]=x;
    return;
}
void pop(){
    f=(f+1)%max;
    return;
}
void fcfs(){
    for(int i=0;i<len;i++){
        if(search(seq[i])==0){
            if(number()==max){
                pop();
            }
            push(seq[i]);
            count++;
        }
    }
    return;
}
void main(){
    printf("no of frames : ");
    scanf("%d",&max);
    printf("length of string seq : ");
    scanf("%d",&len);
    for(int i=0;i<max;i++){
        frame[i]=-1;
    }
    printf("enter string seq : ");
    for(int i=0;i<len;i++){
        scanf("%d",&seq[i]);
    }
    fcfs();
    printf("%d\n",count);
}