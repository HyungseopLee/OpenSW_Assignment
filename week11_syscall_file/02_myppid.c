#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){

    pid_t mypid=getpid();
    pid_t myppid=getppid();
    
    printf("pid: %d\n", mypid);
    printf("ppid: %d\n", myppid);

    return 0;
}