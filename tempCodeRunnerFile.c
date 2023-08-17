void priority(process p[]){
//     int num=n,min,flag;
//     printf("0 ");
//     while(num>0){
//         min=100,flag=0;
//         for(int i=0;i<n;i++){
//             if(p[i].arrival<=time && p[i].flag==0){
//                 if(min>p[i].priority){
//                     min=p[i].priority;
//                     flag=1;
//                     pos=i;
//                 }
//             }
//         }
//         if(flag==1){
//             p[pos].completetion=time;
//             time=time+p[pos].burst;
//             p[pos].turnaround=p[pos].completetion-p[pos].arrival;
//             p[pos].wait=p[pos].turnaround-p[pos].burst;
//             p[pos].flag=1;
//             num--;
//             printf("| P%d | %d |",p[pos].pid,p[pos].completetion);
//         }
//     }
// }