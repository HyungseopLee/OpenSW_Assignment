#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){

    pid_t mypid=getpid();
    
    printf("pid: %d\n", mypid);

    return 0;
}