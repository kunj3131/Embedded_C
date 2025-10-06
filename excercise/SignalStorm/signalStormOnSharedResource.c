/*
 *
 *	Title: Signal Storm on Shared Resource
 *	Description: -> A shared buffer is protected by mutex. -> 5 threads send signals to each other randomly. -> Some signals are blocked. -> Handle SIGUSR1 only in thread 3.
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <sys/wait.h>

char buffer[] = "World";
int count = 1;
pthread_t thread[5];

pthread_mutex_t lock;
pthread_mutexattr_t attr;

void *thread1(){
	while(1){
		pthread_mutex_lock(&lock);
		printf("%d --->  %s\n",count,buffer);
		count++;
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}

void signalHandler(int sig){
        if(sig == SIGUSR1){
                pthread_mutex_lock(&lock);
                printf("Signal recieved\n");
                pthread_mutex_unlock(&lock);

        }
}


void *thread3(){
//      signal(SIGUSR1,signalHandler);
        struct sigaction sa;
        sa.sa_handler = signalHandler;
        sigemptyset(&sa.sa_mask);
        sa.sa_flags = 0;
        sigaction(SIGUSR1,&sa,NULL);

        sigset_t set;
        sigemptyset(&set);
        sigaddset(&set,SIGUSR1);
        pthread_sigmask(SIG_UNBLOCK, &set,NULL);

        while(1){
                pause();
        }

        return NULL;
}


void *thread2(){
	while(1){
		pthread_mutex_lock(&lock);
		printf("Hello\n");
		pthread_mutex_unlock(&lock);
		
		// Randomly send SIGUSR1 to thread 3
		if (rand() % 5 == 0) {
			pthread_kill(thread[3], SIGUSR1);
			exit(0);	
		}

		sleep(1);
	}
		
	return NULL;
}
/*
void signalHandler(int sig){
	if(sig == SIGUSR1){
		pthread_mutex_lock(&lock);
		printf("Signal recieved\n");
		pthread_mutex_unlock(&lock);

	}
}

void *thread3(){
//	signal(SIGUSR1,signalHandler);
	struct sigaction sa;
	sa.sa_handler = signalHandler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1,&sa,NULL);

	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set,SIGUSR1);
	pthread_sigmask(SIG_UNBLOCK, &set,NULL);

	while(1){
		pause();
	}

	return NULL;
}
*/
int main(){
		
	sigset_t sigset;
	sigemptyset(&sigset);
	sigaddset(&sigset,SIGUSR1);
	pthread_sigmask(SIG_BLOCK, &sigset, NULL);

	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_ERRORCHECK);
	pthread_mutex_init(&lock,&attr);
	
	for(int i=1;i<2;i++){
		pthread_create(&thread[i],NULL,thread1,NULL);
	}

	pthread_create(&thread[4],NULL,thread2,NULL);
	pthread_create(&thread[5],NULL,thread2,NULL);
	pthread_create(&thread[3],NULL,thread3,NULL);

	for(int i=1;i<5;i++){
		pthread_join(thread[i],NULL);
	}

	pthread_mutexattr_destroy(&attr);
	pthread_mutex_destroy(&lock);

	for(int i=1;i<=5;i++){
		pthread_exit(&thread[i]);
		
	}
	


	return 0;
}
