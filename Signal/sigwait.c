#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    sigset_t sigset;
    int sig;

    // Step 1: Create a signal set and add SIGINT (Ctrl+C)
    sigemptyset(&sigset);
    sigaddset(&sigset, SIGINT);

  // Step 2: Block SIGINT so it doesn't get delivered to the default handler
    if (sigprocmask(SIG_BLOCK, &sigset, NULL) == -1) {
        perror("sigprocmask");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for SIGINT (Ctrl+C)...\n");

    // Step 3: Wait for SIGINT synchronously
    if (sigwait(&sigset, &sig) == 0) {
        printf("Received signal: %d\n", sig);
    } else {
        perror("sigwait");
        exit(EXIT_FAILURE);
    }

    printf("Exiting gracefully after catching SIGINT.\n");
    return 0;
}

