#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){

    if (argc < 2) {
        printf("Usage: %s <program> [OPTION] ...\n", argv[0]);
        return 0;
    }

    pid_t pid = fork();

    if (pid == 0){
        // child process
        if(execve(argv[1], &argv[1], NULL) == -1){
            exit(1);
        }
    }
    else {
        // parent process
        int wstatus;
        waitpid(pid, &wstatus, 0);
        if (WIFEXITED(wstatus)){
            printf("Child exited with status: %d\n", WEXITSTATUS(wstatus));
        }
        else{
            printf("Child did not exit normally\n");
        }
    }

    return 0;
}