#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
int count=0;
sem_t mutex;
void *counting(){
	pthread_t threadID = pthread_self();
	sem_wait(&mutex);
	for(int i=0;i<1000000;i++){
		count++;	
	}
	printf("%d counting of threadID %lu\n",count,threadID);
	sem_post(&mutex);
}

int main(){
	sem_init(&mutex,0,1);
	pthread_t counti1, counti2;
	pthread_create(&counti1, NULL, counting, NULL);
	pthread_create(&counti2, NULL, counting, NULL);
	pthread_join(counti1,NULL);
	pthread_join(counti2,NULL);
	sem_destroy(&mutex);
	return 0;
}
