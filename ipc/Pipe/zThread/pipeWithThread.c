/*
 *	Title: IPC using Pipe 
 *	
 *	Description: IPC using Pipe between two Threads both threads are send and recv using two pipeline
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

int pipe1[2];
int pipe2[2];

//pthread_mutex_t lock;
//pthread_mutexattr_t attr;

void *func1(){
	while(1){
//		pthread_mutex_trylock(&lock);
//		close(pipe1[0]);
//		close(pipe2[1]);
		char send[]="Hello from 1\n";
		char recv[20];
		write(pipe1[1],send,sizeof(send));
		printf("Sent by Func1: %s\n",send);
		sleep(1);
		read(pipe2[0],recv,sizeof(recv));
		printf("Rec by Func1: %s\n",recv);
		close(pipe1[1]);
		close(pipe2[0]);
//		pthread_mutex_unlock(&lock);

	}
	return NULL;

}

void *func2(){
	while(1){
//		pthread_mutex_trylock(&lock);
//		close(pipe1[1]);
//	        close(pipe2[0]);
		char send[]="Hello from 2\n";
		char recv[20];
	        read(pipe1[0],recv,sizeof(recv));
		printf("Rec by Func2: %s\n",recv);
		sleep(1);
	        write(pipe2[1],send,sizeof(send));
		printf("Sent by Func2: %s\n",send);
	        close(pipe1[0]);
	        close(pipe2[1]);
//		pthread_mutex_unlock(&lock);

	}
	return NULL;

}

int main(){
	pthread_t one,two;
	if(pipe(pipe1)==-1 || pipe(pipe2)==-1){
		printf("Error\n");
	}
	
//	pthread_mutexattr_init(&attr);
	
//	int s=pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_ERRORCHECK);
//	if(s!=0){
//		perror("error\n");
//	}

//	pthread_mutex_init(&lock,&attr);

	pthread_create(&one, NULL, &func1, NULL);
	pthread_create(&two, NULL, &func2, NULL);

	pthread_join(one, NULL);
	pthread_join(two, NULL);

//	pthread_mutexattr_destroy(&attr);
//	pthread_mutex_destroy(&lock);

	return 0;
}
