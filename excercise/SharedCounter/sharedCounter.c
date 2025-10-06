/*
 *
 *	Title: Shared Counter with Pipe and Signals Problem
 *
 *	Description: ->Parent and child share a counter (via pipe).
 *		     ->Child increments it and writes back.
 *		     ->Every 5 seconds, parent sends a SIGUSR1 to log the counter value.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <sys/wait.h>

int pipeData[2];
int counter = 0;
int recv;

void signalhandler(int sig){
	if(sig == SIGUSR1){
		printf("SIGUSR1 is raised\n");
		read(pipeData[0],&recv,sizeof(recv));
		printf("RX: %d\n",recv);
		close(pipeData[1]);
		close(pipeData[0]);
		exit(1);
	}
}

int main(){
	if(pipe(pipeData) == -1){
		printf("Error to creation Pipe\n");
	}

	printf("Parent Counter %d\n",getpid());
	write(pipeData[1],&counter,sizeof(counter));

	pid_t pid = fork();
	
	if(pid == 0){
		printf("Child Process %d\n",getpid());
		read(pipeData[0],&recv,sizeof(recv));
		printf("%d\n",recv);
		counter++;
		printf("Write incremented counter\n");
		write(pipeData[1],&counter,sizeof(counter));
	}

	else if(pid > 0){
		wait(NULL);
		signal(SIGUSR1,signalhandler);
		while(1){
			sleep(5);
			raise(SIGUSR1);
		}
	}
	return 0;
}
