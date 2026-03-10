#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

struct two_double{
    double a;
    double b;
};
struct two_double data;

void sigalarm_handler(int _signo) {
    printf("%f, %f\n", data.a, data.b);
    alarm(1);
}

int main(void){

    struct sigaction sa_sigalrm;
    struct two_double zeros = {0.0, 0.0}, ones = {1.0, 1.0};
    
    sa_sigalrm.sa_handler = sigalarm_handler;
    sigemptyset(&sa_sigalrm.sa_mask);
    sa_sigalrm.sa_flags = 0;
    if(sigaction(SIGALRM, &sa_sigalrm, NULL) == -1){
        perror("sigaction error: ");
        exit(0);
    }
    
    // block SIGALRM using sigprocmask(2)
    sigset_t block_set;
    sigemptyset(&block_set);
    sigaddset(&block_set, SIGALRM);
    
    alarm(1);
    while(1){
        sigprocmask(SIG_BLOCK, &block_set, NULL); // block
        data = zeros;
        sigprocmask(SIG_UNBLOCK, &block_set, NULL); // unblock
        
        sigprocmask(SIG_BLOCK, &block_set, NULL); // block
        data = ones;
        sigprocmask(SIG_UNBLOCK, &block_set, NULL); // unblock
        
    }

    return 0;
}