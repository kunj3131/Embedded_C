#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024  // Size of shared memory

int main() {
    key_t key = ftok("shmfile", 65);  // Generate unique key
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);  // Create shared memory

    if (shmid < 0) {
        perror("shmget failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == 0) {
        // 👶 Child process

        // Attach to shared memory
        char *data = (char *) shmat(shmid, NULL, 0);
        if (data == (char *)(-1)) {
            perror("shmat failed (child)");
            exit(1);
        }

        // Write to shared memory
        strcpy(data, "Hello from child process!");

        printf("Child: Wrote to shared memory.\n");

        // Detach
        shmdt(data);

    } else if (pid > 0) {
        // 👴 Parent process

        wait(NULL);  // Wait for child to finish

        // Attach to shared memory
        char *data = (char *) shmat(shmid, NULL, 0);
        if (data == (char *)(-1)) {
            perror("shmat failed (parent)");
            exit(1);
        }

        // Read from shared memory
        printf("Parent: Read from shared memory: %s\n", data);

        // Detach and delete
        shmdt(data);
        shmctl(shmid, IPC_RMID, NULL);  // Remove shared memory

    } else {
        perror("fork failed");
        exit(1);
    }

    return 0;
}

