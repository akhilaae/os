#include <stdio.h>
#include <stdlib.h>
int n;
typedef struct{
    int pid;
    int arrival;
    int burst;
    int turnaround;
    int wait;
    int completion;
    int flag;
}process;
process p[10];
int pos,time=0;
void sort(process p[]){
    int small;
    process temp;
    for(int i=0;i<n-1;i++){
        small=i;
        for(int j=i+1;j<n;j++){
            if(p[j].arrival<p[small].arrival){
                small=j;
            }
        }
        if(small!=i){
            temp=p[i];
            p[i]=p[small];
            p[small]=temp;
        }
    }
}
void sjf(process p[]){
    int num=n,min,flag;
    printf("0 ");
    while(num>0){
        min=10000,flag=0;
        for(int i=0;i<n;i++){
            if(p[i].arrival<=time && p[i].flag==0){
                if(min>p[i].burst){
                    min=p[i].burst;
                    flag=1;
                    pos=i;
                }
            }
        }
        if(flag==1){
            time=time+p[pos].burst;
            p[pos].completion=time;
            p[pos].turnaround=p[pos].completion-p[pos].arrival;
            p[pos].wait=p[pos].turnaround-p[pos].burst;
            p[pos].flag=1;
            num--;
            printf("| P%d | %d |",p[pos].pid,p[pos].completion);
        }
        else{
            time+=1;
        }
    }
}
void avg(process p[]){
    int tw=0,tt=0;
    for(int i=0;i<n;i++){
        tw+=p[i].wait;
        // printf("%d",tw);
        tt+=p[i].turnaround;
    }
    // printf("%d",tw);
    printf("\navg wt : %d",tw/n);
    printf("\navg tt : %d",tt/n);
    
}
void main(){
    // int m;
    printf("no process : ");
    scanf("%d",&n);
    printf("input : ");
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&p[i].pid,&p[i].arrival,&p[i].burst);
        p[i].flag=0;
    }
    sort(p);
    sjf(p);
    // gantt();
    avg(p);
}