#include <stdio.h>
int n,m,block_size[10],process_size[10],block_allocated[10],block_allocated_size[10],block_flag[10],frag[10];
int indexed;
void init(){
     for(int i=0;i<n;i++){
        block_flag[i]=-1;
    }
    for(int i=0;i<n;i++){
        block_allocated[i]=0;
        block_allocated_size[i]=0;
        frag[i]=0;
    }
}
void display(){
    for(int i=0;i<m;i++)
        printf("%d  %d  %d  %d  %d\n",i+1,process_size[i],block_allocated[i],block_allocated_size[i],frag[i]);
}
void first(){
    int size;
    for(int i=0;i<m;i++){
        size=process_size[i];
        for(int j=0;j<n;j++){
            if(block_flag[i]==-1){
                if(size<block_size[j]){
                    block_allocated[i]=j+1;
                    frag[i]=block_size[j]-size;
                    block_allocated_size[i]=block_size[j];
                    block_flag[i]=1;
                    break;
                }
            }
        }
    }
}
int max(){
    int large=0;
    for(int i=0;i<n;i++){
        if(block_flag[i]==-1){
            if(block_size[i]>large){
                large=block_size[i];
                indexed=i;
            }
        }
    }
    return large;
}
void worst(){
    int size,x;
    for(int i=0;i<m;i++){
        size=process_size[i];
        x=max();
        if(size<x){
            frag[i]=block_size[indexed]-size;
            block_flag[indexed]=1;
            block_allocated[i]=indexed+1;
            block_allocated_size[i]=block_size[indexed];
        }
    }
}
int min(int num){
    int small,size_req;
    for(int i=0;i<n-1;i++){
        small=i;
        for (int j=i+1;j<n;j++){
            if(block_size[j]<block_size[small]){
                small=j;
            }
        }
        if(small!=i){
            int temp=block_size[i];
            block_size[i]=block_size[small];
            block_size[small]=temp;
        }
    }
    for(int i=0;i<n;i++){
        if(num<block_size[i]){
            size_req=block_size[i];
            indexed=i;
            break;
        }
    }
    return size_req;
}
void best(){
    int size,temp,x;
    for(int i=0;i<m;i++){
        size=process_size[i];
        x=min(size);
        if(size<x){
            frag[i]=block_size[indexed]-size;
            block_flag[indexed]=1;
            block_allocated[i]=indexed+1;
            block_allocated_size[i]=block_size[indexed];
        }
    }
}
void main(){
    printf("input no of blocks : ");
    scanf("%d",&n);
    printf("input no of processes : ");
    scanf("%d",&m);
    printf("Enter size of each block : \n");
    for(int i=0;i<n;i++){
        printf("block %d : ",i+1 );
        scanf("%d",&block_size[i]);
    }
    printf("Enter size of each process : \n");
    for(int i=0;i<m;i++){
        printf("process %d : ",i+1 );
        scanf("%d",&process_size[i]);
    }
    init();
    first();
    display();
    init();
    worst();
    display();
    init();
    best();
    display();
}