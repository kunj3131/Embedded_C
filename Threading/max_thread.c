

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4194304  // Adjust based on your system

void *foo(void *arg) {           
    pthread_t threadID = pthread_self();
    printf("Hello World from thread %lu\n", threadID);
    return NULL;
}

int main() {
    pthread_t *threads = malloc(sizeof(pthread_t) * NUM_THREADS);
    if (threads == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        int rc = pthread_create(&threads[i], NULL, foo, NULL);
        if (rc) {
            fprintf(stderr, "Error creating thread %d: %d\n", i, rc);
            break;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    free(threads);
    return 0;
}
