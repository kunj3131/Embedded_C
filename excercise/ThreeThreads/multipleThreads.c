/*
 *
 *	Title: Create a 3 Threads, Thread 1 handle SIGUSR1, Thread 2 Handle SIGUSR2, Thread 3 Handle perform some task and sleeping loop
 *
 *	Mask SIGUSR1 in main Thread, use sigwait() in one thread to handle
 *	
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <pthread.h>

sigset_t set;

void user1signal(int sig){	
	while(1){
		printf("Signal recieved USR1 %d\n",sig);
	}
	exit(0);
}

void user2signal(int sig){

		printf("Signal recieved USR2 %d\n",sig);

	exit(0);
}

void *thread1(void *arg){
	signal(SIGUSR1,user1signal);
	printf("Thread 1 for SIGUSR1\n");
	int sig;
	if(sigwait(&set,&sig)==0){
		if(sig == SIGUSR1){
			printf("Recved signal SIGUSR1\n");
		}
	}
	return NULL;
}

void *thread2(){
	
	printf("Thread 2 for SIGUSR2\n");
	return NULL;
}

void *thread3(void *arg){
	int i=0;
    	pthread_t *thread1_id = (pthread_t *)arg;
	while(1){
		printf("Thread 3 for sleeping loop\n");
		sleep(2);
		i++;
		if(i==4){
		//	raise(SIGUSR2);
			sleep(1);
		//	raise(SIGUSR1);	
			pthread_kill(*thread1_id, SIGUSR1);
			exit(1);
		}
	}
	return NULL;
}

int main(){
	sigemptyset(&set);
	sigaddset(&set,SIGUSR1);

	pthread_sigmask(SIG_BLOCK,&set,NULL);

	pthread_t Thread1, Thread2, Thread3;

	pthread_create(&Thread1,NULL,thread1,NULL);
	pthread_create(&Thread2,NULL,thread2,NULL);
	pthread_create(&Thread3,NULL,thread3,&Thread1);

	pthread_join(Thread1,NULL);
	pthread_join(Thread2,NULL);
	pthread_join(Thread3,NULL);

	return 0;
}
