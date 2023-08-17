#include <stdio.h>
void main(){
    int blocks[100],n,b,len,ch;
    printf("Enter no of blocks : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        blocks[i]=0;
    }
    do{
        printf("enter file beg : ");
        scanf("%d",&b);
        printf("length : ");
        scanf("%d",&len);
        if(b+len-1>n-1){
            printf("not possible!\n");
        }
        else{
            int f=0;
            for(int i=b;i<b+len;i++){
                if(blocks[i]!=0){
                    f=1;
                    break;
                }
            }
            if(f==0){
                printf("allocation occurs!\n");
                for(int i=b;i<b+len;i++){
                    blocks[i]=1;
                    printf("%d",i);
                }
            }
            else{printf("not possible!\n");}
        }
        printf("enter choice (ch=1 to continue) : ");
        scanf("%d",&ch);
    }
    while(ch!=0);
}