#include <stdio.h>
#include <dirent.h>
void main(){
    DIR* dir=opendir("hehe");
    if(dir!=NULL){
        printf("set");
        struct dirent* de;
        while((de=readdir(dir))!=NULL){
            printf("%s",de->d_name);
        }
    }
    else{
        printf("notset");
    }
}