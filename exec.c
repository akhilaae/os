 #include <stdio.h>
 #include <io.h>
 void main(){
    int pid=fork();
    if (pid<0){
        printf("fork fail");
    }
    else if(pid==0){
        printf("child process %d executing",getpid());
        printf("bring prg.c");
        char* argv[]={"prg",NULL};
        exec("./prg",argv);
    }
    else{
        printf("parent process %d executing",getpid());
    }
 }