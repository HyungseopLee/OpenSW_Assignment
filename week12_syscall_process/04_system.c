#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int mysystem(const char* command) {
    pid_t pid = fork();

    if (pid == 0) {
        // child process
        execl("/bin/sh", "sh", "-c", command, (char *)NULL);
        exit(127); // exec failed
    } else if (pid > 0) {
        // parent process
        int wstatus;
        waitpid(pid, &wstatus, 0);
        if (WIFEXITED(wstatus)) {
            return WEXITSTATUS(wstatus);
        } else {
            return -1; // child did not exit normally
        }
    } else {
        // fork failed
        return -1;
    }
}

int main(void) {

    // system("ls -l | wc -l");
    // system("find . -name '*.c'");

    mysystem("ls -l | wc -l");
    mysystem("find . -name '*.c'");

    printf("Good Bye~\n");

    return 0;
}