 #include <stdio.h>
 #include <unistd.h>
 #include <sys/wait.h>
 void main(){
    int pid=fork();
    if (pid<0){
        printf("fork fail");
    }
    else if(pid==0){
        printf("child process %d executing\n",getpid());
    }
    else{
        printf("parent process %d executing\n",getpid());
        int status;
        printf("parent waiting for child to terminate\n");
        int pid=wait(&status);
        
        printf("parent wait over child %d exited\n",pid);
        printf("parent over %d\n",getpid());
    }
 }