/*
	Build a system where:
		The main process creates a child process.
		The child spawns a thread that buffers log messages.
		Parent sends messages to child via a pipe.
		On receiving a message, the child thread stores it in memory.
		On SIGUSR1, the child writes the buffered logs to a file. (All logs should be saved to logs.txt when SIGUSR1 is sent to the child.)
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>

int pipeq[2];
char sendData[] = "Process sending a Data to Child";
char recv[50];

FILE *fptr;

void signalHandler(int sig){
	printf("\nSIGUSR1 is generated\n");
	fclose(fptr);
	exit(1);
}

void *thread(void *recieveData){
	fptr = fopen("logs.txt","w");
	fprintf(fptr,"%s",(char *)recieveData);
//	fclose(fptr);
}

int main(){
	if(pipe(pipeq) == -1){
		printf("Error in pipe creation\n");
		return 1;
	}	
	printf("Parent Process: %d\n",getpid());
	pid_t pid = fork();

	if(pid > 0){
		write(pipeq[1],&sendData,sizeof(sendData));
		close(pipeq[1]);
		printf("Data is sent by Process to Child\n");
		wait(NULL);
	}

	else if(pid == 0){
	//	wait(NULL);
		read(pipeq[0],&recv,sizeof(recv));
		close(pipeq[0]);
		printf("Received Data: %s\n",recv);

		pthread_t logger;
		pthread_create(&logger, NULL, thread, recv);
		pthread_join(logger,NULL);
		pthread_cancel(logger);
		
		signal(SIGUSR1,signalHandler);
		while(1){
			getchar();
			raise(SIGUSR1);
		}

	}

	return 0;
}

