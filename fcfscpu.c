#include <stdio.h>
int n;
typedef struct{
    int pid;
    int arrival;
    int burst;
    int wait;
    int turnaround;
    int comp;
}process;
process p[10];
int time=0;
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
void fcfs(process p[]){
    for(int i=0;i<n;i++){
        if(time<p[i].arrival){
            time=p[i].arrival;
        }
        time+=p[i].burst;
        p[i].comp=time;
        p[i].turnaround=p[i].comp-p[i].arrival;
        p[i].wait=p[i].turnaround-p[i].burst;
    }
}
void gantt(process p[]){
    int x;
    for(int i=0;i<n;i++){
        printf("| P%d ",i+1);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d    ",p[i-1].comp);
        x=i;
    }
    printf("%d    ",p[x].comp);
}
void avg(process p[]){
    int totalwt=0,totaltat=0;
    for(int i=0;i<n;i++){
        totalwt+=p[i].wait;
        totaltat+=p[i].turnaround;
    }
    printf("\navg wt : %f",totalwt/n);
    printf("\navg tat : %f",totaltat/n);
}
void main(){
    printf("no of process : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&p[i].pid,&p[i].arrival,&p[i].burst);
    }
    sort(p);
    fcfs(p);
    gantt(p);
    avg(p);
}