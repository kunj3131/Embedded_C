/*
 *
 *	Title: Create a Two Process in main. Both are writing a data into single pipe. 
 *	-> Create a Thread which reads a data from Pipe and in 3 seconds if in pipe data is not availble rasie an alarm.
 *
 *
 */



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <sys/wait.h>

int pipeData[2];
char recv[30];
pthread_t thread1;

void signalAlarm(int sig){
	if(sig == SIGALRM){
		printf("Signal is generated No data rx\n");
		kill(getpid(),SIGALRM);
		pthread_exit(&thread1);
	}
}

void *reader(){
	while(1){
	//	signal(SIGALRM,signalAlarm);
		alarm(3);
		if(read(pipeData[0],recv,sizeof(recv))>0){
			printf("Rx: %s\n",recv);	
			alarm(0);
		}
	}
	return NULL;
}

int main(){
	if(pipe(pipeData)==-1){
        	printf("Error\n");
	}

	signal(SIGALRM,signalAlarm);

	char sendChar1[] = "Hello World from 1";
	char sendChar2[] = "Hello World from 2";
	
	printf("Parent Process %d\n",getpid());
	pid_t pid1, pid2;

	pthread_create(&thread1,NULL,reader,NULL);
	
	pid1 = fork();
	if(pid1 == 0){
	//	close(pipeData[0]);
	//	sleep(2);
		write(pipeData[1],sendChar1,sizeof(sendChar1));
		printf("Tx1: %s\n",sendChar1);
		close(pipeData[1]);
		exit(0);
	}

	if(pid1>0){
		wait(NULL);
		pid2 = fork();
		if(pid2 == 0){
		//	close(pipeData[0]);
			sleep(4);
			write(pipeData[1],sendChar2,sizeof(sendChar2));
			printf("Tx2: %s\n",sendChar2);
			close(pipeData[1]);
			exit(0);
		}
	}
	
	if(pid1 > 0 && pid2 > 0){
		close(pipeData[1]);
		pthread_join(thread1,NULL);
		close(pipeData[0]);
	}

	return 0;
}
