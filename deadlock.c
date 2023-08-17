#include <stdio.h>
#include <stdlib.h>\''
int available[10],allocation[10][10],request[10][10];
void main(){
    int m,n;
    printf("no of processes : ");
    scanf("%d",&n);
    printf("no of resources : ");
    scanf("%d",&m);
    printf("available : ");
    for(int i=0;i<m;i++){
        scanf("%d",&available[i]);
    }
    printf("allocation : ");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&allocation[i][j]);
        }
    }
    printf("request : ");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&request[i][j]);
        }
    }
    int * work =(int *)malloc(m*sizeof(int));
    int * finish =(int *)malloc(n*sizeof(int));

    for(int i=0;i<m;i++){
        work[i]=available[i];
    }

    for(int i=0;i<n;i++){
        int f=0;
        for(int j=0;j<m;j++){
            if (allocation[i][j]!=0){
                f=1;
                break;
            }
        }
        if(f==0){
            finish[i]=1;
        }
        else{
            finish[i]=0;
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(finish[i]==0){
                int flag=0;
                for(int j=0;j<m;j++){
                    if(request[i][j]>work[j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    for(int z=0;z<m;z++){
                        work[z]+=allocation[i][z];
                    }
                    finish[i]=1;
                }
            }
            
            
        }
    }
    int fl=0;
    for(int i=0;i<n;i++){
        if(finish[i]==0){
            fl=1;
            printf("deadlock detected!");
            break;
        }
    }
    if(fl==0){
        printf("no deadlock!");
    }
}