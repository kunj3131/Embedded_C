#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

sigset_t set;

void* thread1(void* arg) {
    printf("Thread 1 for SIGUSR1\n");

    int sig;
    if (sigwait(&set, &sig) == 0) {
        printf("Thread 1: Received signal: %d\n", sig);
    } else {
        perror("sigwait failed");
    }

    return NULL;
}

void* thread2(void* arg) {
    printf("Thread 2 for SIGUSR2\n");
    return NULL;
}

void* thread3(void* arg) {
    pthread_t* thread1_id = (pthread_t*)arg;

    int i = 0;
    while (1) {
        printf("Thread 3 for sleeping loop\n");
        sleep(2);
        i++;
        if (i == 4) {
            printf("Thread 3: Sending SIGUSR1 to Thread 1\n");
            int result = pthread_kill(*thread1_id, SIGUSR1);
            if (result != 0) {
                printf("Failed to send signal: %d\n", result);
            }
            return NULL;
        }
    }
}

int main() {
    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);

    pthread_sigmask(SIG_BLOCK, &set, NULL);

    pthread_t Thread1, Thread2, Thread3;

    pthread_create(&Thread1, NULL, thread1, NULL);
    pthread_create(&Thread2, NULL, thread2, NULL);
    pthread_create(&Thread3, NULL, thread3, &Thread1);  // Pass &Thread1

    pthread_join(Thread1, NULL);
    pthread_join(Thread2, NULL);
    pthread_join(Thread3, NULL);

    return 0;
}

