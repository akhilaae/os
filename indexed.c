#include <stdio.h>
#include <stdlib.h>
void main(){
    int n,start,length,ch;
    printf("no of blocks : ");
    scanf("%d",&n);
    int* blocks=(int*)malloc(sizeof(int));
    for(int i=0;i<n;i++){
        blocks[i]=-1;
    }
    
    do{
        printf("starting block : ");
        scanf("%d",&start);
        
        if(blocks[start]!=-1){
            printf("head already allocated !!\n");
        }
        else{
            printf("length : ");
            scanf("%d",&length);
            int index_block[100];
            blocks[start]=1;
            int count=0,i;
            for(i=0;i<n && count<length;i++){
                if(blocks[i]==-1){
                    blocks[i]=1;
                    index_block[count]=i;
                    count++;
                }
            }
            if(i==n && count<length){
                printf("insufficient memory\n");
                for(int i=0;i<n;i++){
                    blocks[index_block[i]]=-1;
                }
                blocks[start]=0;
            }
            else{
                printf("allocated!!\nblocks are : ");
                for(int i=0;i<count;i++){
                    printf("%d ",index_block[i]);
                }
            }
        }
        printf("Continue?1/0 : ");
        scanf("%d",&ch);
    }
    while(ch!=0);
}