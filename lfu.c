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
int freq(int n,int index){
    int c=0;
    for(int l=index-1;l>=0;l--){
        if(n==seq[l]){
            c++;
        }
    }
    return c;
}
void lfu(){
    int small,f,index,temp,a[10];
    for(int i=0;i<len;i++){
        for(int j=0;j<max;j++){
            if(number()!=max){
                push(seq[i]);
                count++;
                display();
                break;
            }
            else{
                if (search(seq[i])==-1)
                {
                    for(int k=0;k<max;k++){
                        f=freq(frame[k],i);
                        a[k]=f;
                    }
                    int num,x=0;
                    for(int p=0;p<max;p++){
                        num=a[p];
                        for(int r=p+1;r<max;r++){
                            if(num==a[r]){
                                x+=1;
                            }
                        }
                        
                    }
                    if(x>0){
                        pop();
                        push(seq[i]);
                        count++;
                        display();
                    }
                    else{
                        frame[k]=seq[i];
                        count++;
                        display();
                    }
                    
                }
                else{//hit(repeat)
                    r=(r+1)%max;
                    display();
                }
                
            }
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
    lfu();
    printf("%d",count);
}