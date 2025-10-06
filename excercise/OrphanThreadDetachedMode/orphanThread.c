/*
 *
 * 	Title: Orphan Thread in Detached Mode Problem
 *
 * 	Description:-> Fork a child process. -> Child starts a detached thread that sleeps for 5 seconds and prints a message.
 * 	            -> Child exits immediately (without waiting for the thread).                        
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <signal.h>

pid_t pid;
pthread_t thread;


void signalHandler(int sig){
	pthread_exit(NULL);
	exit(0);
}

void *printing(void *arg){
        sleep(2);
        printf("Hello World\n");
	kill(getpid(),SIGTERM);			//Ideal way to terminate the process
}

/*
 * 		Reason to use of kill. if I use 'raise(SIGTERM)' or use 'exit(1)' Parent Process terminates but in backend the child process still active because we use "pause()" 
 *	so we have to check using 'htop' command in that using kill we doing a terminate the specific process using "getpid()".
 *
 */



int main(){
    printf("Parent Process %d\n", getpid());
    signal(SIGTERM,signalHandler);
    pid = fork();
    if(pid == 0){
        printf("Child Process %d\n", getpid());
        pthread_create(&thread, NULL, printing, NULL);
        pthread_detach(thread);
        pause();
	exit(1);
    }
    return 0;
}

