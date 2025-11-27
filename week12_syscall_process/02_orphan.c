#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){

    pid_t pid = fork();

    if (pid == 0) {
        // child process
        sleep(1);
        printf("Child process PID: %lu\n", (unsigned long)getpid());
        printf("Child process PPID: %lu\n", (unsigned long)getppid());
        exit(7);
    }

    else{
        // parent process
        // int wstatus;
        // waitpid(pid, &wstatus, 0);
        // if (WIFEXITED(wstatus)){
        //     printf("Child exited with status: %d\n", WEXITSTATUS(wstatus));
        // }
        // else{
        //     printf("Child did not exit normally\n");
        // }

        printf("Parent process PID: %lu\n", (unsigned long)getpid());
        printf("Parent process PPID: %lu\n", (unsigned long)getppid());
    }

    return 0;
}