#include <stdio.h>
#include <stdlib.h>
typedef struct block{
    int block_no;
    struct block* next;
}block;
typedef struct{
    int start_block;
    int length;
    block* list;
}file;
int blocks[100];
void main(){
    int n,ch;
    printf("enter no of freeblocks : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        blocks[i]=-1;
    }
    do{
        file *ptr=(file*)malloc(sizeof(file));
        
        printf("start block : ");
        scanf("%d",&ptr->start_block);
        printf("length : ");
        scanf("%d",&ptr->length);
        if(blocks[ptr->start_block]==1){
            printf("head already allocated");
        }
        else{
            block* p=(block*)malloc(sizeof(block));
            (ptr->list)=p;
            p->block_no=ptr->start_block;
            p->next=NULL;
            blocks[p->block_no]=1;
        
            int count=1,i;
            for(i=0;((i<n)&&(count<(ptr->length)));i++){
                if(blocks[i]==-1){
                    block* new=(block*)malloc(sizeof(block));
                    new->next=NULL;
                    new->block_no=i;
                    block* temp=ptr->list;
                    while(temp->next!=NULL){
                        temp=temp->next;
                    }
                    temp->next=new;
                    
                    count++;
                    blocks[i]=1;
                }
            }
            if((i==n) && count<(ptr->length)){
                printf("insufficient storage\n");
            }
            else{
                printf("allocated!");
                block* x=ptr->list;
                while(x->next!=NULL){
                    printf("%d->",x->block_no);
                    x=x->next;
                }
                printf("%d",x->block_no);
            }
        }
        printf("choose : 0/1");
        scanf("%d",&ch);
    }
    while(ch!=0);
}