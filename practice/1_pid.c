#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

pid_t getpid(void);
pid_t getppid(void);

int main(void){

    pid_t pid = getpid();
    pid_t ppid = getppid();

    printf("pid = %d\n", pid);
    printf("ppid = %d\n", ppid);

    return 0;
}