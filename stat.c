#include <stdio.h>
#include <sys/stat.h>
void main(){
    struct stat status;
    stat("a.txt",&status);
    printf("%d %d %d",status.st_size,status.st_mode,status.st_dev);
}