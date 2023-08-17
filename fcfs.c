#include <stdio.h>
int max,f=-1,r=-1,i,j,k,p;
int frame[100],seq[100],len,count=0;
int search(int x){
    for(j=0;j<max;j++){
        if(frame[j]==x){
            return 1;
        }
    }
    return 0;
}
int number(){
    int frame_now_size=0;
    for(k=0;k<max;k++){
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
void fcfs(){
    for (i = 0; i < len; i++)
    {
        if (search(seq[i])==0){
            if (number()==max){
                pop();
                push(seq[i]);
                count++;
            }
            else{
                push(seq[i]);
                count++;
            }
        }
        display();
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
    fcfs();
    printf("%d",count);
}