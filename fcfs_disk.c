#include <stdio.h>
#include <math.h>
int n,request[20],head,seekcount=0;
void main(){
    printf("enter size : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&request[i]);
    }
    printf("head : ");
    scanf("%d",&head);
    for(int i=0;i<n;i++){
        printf("%d ",request[i]);
        seekcount+=abs(request[i]-head);
        head=request[i];
    }
    printf("\n%d\n",seekcount);
}