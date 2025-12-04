#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void sigint_handler(int signum) {
    printf("[SIGINT handler] ------------\n");
    pid_t pid = fork();

    if (pid == 0) { // child
        char *argv[] = {"ls", NULL};
        execve("/usr/bin/ls", argv, NULL);
        perror("execve ls error");
        exit(1);
    }
    else { // parent
        int status;
        waitpid(pid, &status, 0);
    }
}

void sigquit_handler(int signum) {
    printf("[SIGQUIT handler] ------------\n");
    pid_t pid = fork();

    if (pid == 0) { // child
        char *argv[] = {"ls", NULL};
        execve("/usr/bin/date", argv, NULL);
        perror("execve ls error");
        exit(1);
    }
    else { // parent
        int status;
        waitpid(pid, &status, 0);
    }
}

void sigalrm_handler(int signum) {
    printf("[SIGALRM handler] ------------\n");
    pid_t pid = fork();

    if (pid == 0) { // child
        char *argv[] = {"ls", NULL};
        execve("/usr/bin/whoami", argv, NULL);
        perror("execve ls error");
        exit(1);
    }
    else { // parent
        int status;
        waitpid(pid, &status, 0);
    }
    alarm(3);
}


int main(void){

    struct sigaction sa_sigint;
    struct sigaction sa_sigquit;
    struct sigaction sa_sigalrm;

    sa_sigint.sa_handler = sigint_handler;
    sa_sigquit.sa_handler = sigquit_handler;
    sa_sigalrm.sa_handler = sigalrm_handler;

    sigaction(SIGINT, &sa_sigint, NULL);
    sigaction(SIGQUIT, &sa_sigquit, NULL);
    sigaction(SIGALRM, &sa_sigalrm, NULL);

    sigemptyset(&sa_sigint.sa_mask);
    sigemptyset(&sa_sigquit.sa_mask);
    sigemptyset(&sa_sigalrm.sa_mask);

    alarm(3);

    while(1){
        sleep(1);
    }

    return 0;
}