#include <pthread.h>
#include <stdio.h>
#include <unistd.h> 

void *detached_thread_function(void *arg) {
    printf("Detached thread: Starting work...\n");
    sleep(2);
    printf("Detached thread: Work finished.\n");
}

int main() {
    pthread_t tid;
    int rc;

    printf("Main thread: Creating detached thread...\n");

    pthread_create(&tid, NULL, detached_thread_function, NULL);

    pthread_detach(tid);

    printf("Main thread: Thread detached. Main thread continuing...\n");

    sleep(2);
    printf("Main thread: Exiting.\n");

    return 0;
}
