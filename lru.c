#include <stdio.h>
int max,f=-1,r=-1,i,j,k,p;
int frame[100],seq[100],len,count=0;
int search(int x){
    for(int j=0;j<max;j++){
        if(frame[j]==x){
            return j;
        }
    }
    return -1;
}
int number(){
    int frame_now_size=0;
    for(int k=0;k<max;k++){
        if(frame[k]!=-1){
            frame_now_size++;
        }
    }
    return frame_now_size;
}
void push(int x){
	if (f==-1 && r==-1)
		{f=0;r=0;}
	else 
		r=(r+1)%max;

	frame[r]=x;
}
void pop(){
    f=(f+1)%max;
}
void display(){
	for(p=0;p<max;p++){
        printf("%d\t",frame[p]);
    }
    printf("\n");
}
int recent(int index){
    int small=index-1,s=0;
    for(int k=0;k<max;k++){
        for(int j=index-1;j>=0;j--){
            if (seq[j]==frame[k] && j<=small){
                small=j;
                s=1;
                break;
            }
            if(seq[j]==frame[k] && j>small){
                break;
            }
        }
    }
    if(s==0){
        return -1;
    }
    return small;
}
void lru(){
    int x;
    for(int i=0;i<len;i++){
        if(search(seq[i])==-1){//miss
            if(number()!=max){//less thn 3
                push(seq[i]);
                display();
            }
            else{//full non repeating
                int small=recent(i);
                if(small==-1){
                    pop();
                    push(seq[i]);
                }
                else{
                    int index=search(seq[small]);
                    frame[index]=seq[i];
                    r=index;
                }
                display();
            }
            count++;
        }
        else{
            // int small=recent(i);
            r=(r+1)%max;//hit
            display();
        }
    }
}
void main(){
    printf("Enter no of frames : ");
    scanf("%d",&max);
    for(i=0;i<max;i++){
        frame[i]=-1;
    }
    printf("string sequence l : ");
    scanf("%d",&len);
    for (i = 0; i < len; i++)
    {
        scanf("%d",&seq[i]);
    }
    lru();
    printf("%d",count);
}