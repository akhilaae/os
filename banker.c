#include <stdio.h>
int allocation[10][10],max[10][10],available[10],need[10][10];
void main(){
    int m,n;
    printf("Enter no of processes : ");
    scanf("%d",&n);
    printf("Enter no of resources : ");
    scanf("%d",&m);
    for(int i=0;i<n;i++){
        printf("allocation:");
        for(int j=0;j<m;j++){
            scanf("%d",&allocation[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        printf("max:");
        for(int j=0;j<m;j++){
            scanf("%d",&max[i][j]);
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
    printf("available : ");
    for(int i=0;i<m;i++){
        scanf("%d",&available[i]);
    }
    int finish[10],z=0,safeseq[10];
    for(int i=0;i<n;i++){
        finish[i]=0;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if (finish[i]==0)
            {
                int flag=0;
                for(int j=0;j<m;j++){
                    if(need[i][j]>available[j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    safeseq[z++]=i;
                    for(int y=0;y<m;y++){
                        available[y]+=allocation[i][y];
                    }
                    finish[i]=1;
                }
            }
        }
    }
    printf("safeseq : ");
    for(int i=0;i<n-1;i++){
        printf("%d ",safeseq[i]);
    }
    printf("%d ",safeseq[n-1]);
}