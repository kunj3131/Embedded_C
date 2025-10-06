#include <stdio.h>
#include <pthread.h>

void *foo(void *arg){
	while(1){
		pthread_t threadID = pthread_self();
		printf("Hello World %lu\n",threadID);
	}
		return NULL;
}

void *anotherFun(){
	while(1){
		pthread_t threadID = pthread_self();
		printf("Hey thread %lu\n",threadID);
	}
		return NULL;
}

int main(){
	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL,foo,NULL);
	pthread_create(&thread2,NULL,anotherFun,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_cancel(thread1);
	pthread_cancel(thread2);
	return 0;
}
