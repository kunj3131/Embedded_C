/*
 *
 *	Title: Race Condition Analyzer Problem
 *	
 *	Description: Two threads increment a shared global value. -> A third thread logs the value every second. -> No mutex is used. 
 * 			->Add murtex and Compare
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <sys/wait.h>

int globalValue = 1;

pthread_mutex_t lock;
pthread_mutexattr_t attr;

void *thread1(){
	while(1){
		pthread_mutex_lock(&lock);
		printf("Thread 1 value : %d\n",globalValue);
		globalValue++;
		pthread_mutex_unlock(&lock);
		sleep(0.8);
		if(globalValue == 100){
			pthread_kill(pthread_self(),SIGKILL);
		}
	}
	return NULL;
}

void *thread2(){
        while(1){
		pthread_mutex_lock(&lock);
                printf("Thread 2 value : %d\n",globalValue);
                globalValue++;
		pthread_mutex_unlock(&lock);
                sleep(0.8);
                if(globalValue == 100){
                        pthread_kill(pthread_self(),SIGKILL);
                }
        }
        return NULL;
}

void *thread3(){
	while(1){
		sleep(1);
		printf("Thread 3 Value -------------------: %d\n",globalValue);
	}
	return NULL;
}

int main(){
//	signal(SIGUSR1,signalhandler);
	pthread_t Thread1, Thread2, Thread3;
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_ERRORCHECK);
	pthread_mutex_init(&lock,&attr);
	pthread_create(&Thread1,NULL,thread1,NULL);
	pthread_create(&Thread2,NULL,thread2,NULL);
	pthread_create(&Thread3,NULL,thread3,NULL);
	
	pthread_join(Thread1,NULL);
	pthread_join(Thread2,NULL);
	pthread_join(Thread3,NULL);

	pthread_mutexattr_destroy(&attr);
	pthread_mutex_destroy(&lock);
	printf("Hello\n");

	pthread_exit(&Thread1);
	pthread_exit(&Thread2);
	pthread_exit(&Thread3);

	return 0;
}
