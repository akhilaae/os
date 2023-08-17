#include <stdio.h>
#include <math.h>
void main(){
    int n,head,req[10],final[10],sort[10],i,l1,l2;
    printf("Enter max : ");
    scanf("%d",&n);
    printf("head : ");
    scanf("%d",&head);
    printf("Enter requests : \n");
    for(i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    printf("limits : ");
    scanf("%d %d",&l1,&l2);
    req[i]=head;
    req[i+1]=l2;
    n=n+2;
    int j,small;
    for(i=0;i<n-1;i++){
        small=i;
        for (j=i+1;j<n;j++){
            if(req[j]<req[small]){
                small=j;
            }
        }
        if(small!=i){
            int temp=req[i];
            req[i]=req[small];
            req[small]=temp;
        }
        
    }
    int head_index;
    for(i=0;i<n;i++){
        if(req[i]==head){
            head_index=i;
            break;
        }
    }
    int seek_count=0;
    for(i=head_index;i<n;i++){
        printf("%d ",req[i]);
        int distance=head;
        seek_count+=abs(req[i]-distance);
        head=req[i];
    }
    for(i=head_index-1;i>=0;i--){
        printf("%d ",req[i]);
        int distance=head;
        seek_count+=abs(req[i]-distance);
        head=req[i];
    }
    printf("\nseekcount : %d",seek_count);
}