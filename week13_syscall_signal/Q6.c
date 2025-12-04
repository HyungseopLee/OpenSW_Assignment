#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(void) {

    // SIGINT signal blocking
    sigset_t block_set;
    sigemptyset(&block_set);
    sigaddset(&block_set, SIGINT);
    sigprocmask(SIG_BLOCK, &block_set, NULL);

    printf("SIGINT blocked. Sleeping for 5 seconds...\n");
    printf("Try Ctrl + C during sleep.\n");
    // sleep for 5 secs
    sleep(5);

    sigset_t pending_signals;
    sigpending(&pending_signals);
    if (sigismember(&pending_signals, SIGINT)) {
        printf("\nSIGINT is pending\n");
    }
    else {
        printf("\nSIGINT is not pending\n");
    }

    return 0;
}