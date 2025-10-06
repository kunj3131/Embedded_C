#include <stdio.h>
#include <pthread.h>

int maxCount = 0;
pthread_mutex_t lock;
int Count = 10000000;
void *counting(){
	pthread_t threadID = pthread_self();
	for(int i=0;i<Count;i++){
		pthread_mutex_lock(&lock);
		maxCount++;
		pthread_mutex_unlock(&lock);
	}
	printf("Counting value %d of threadID %lu\n",maxCount, threadID);
	return NULL;
}

int main(){
	pthread_t counting1, counting2;
	
	pthread_mutex_init(&lock,NULL);

	pthread_create(&counting1, NULL, counting, NULL);
	pthread_create(&counting2, NULL, counting, NULL);

	pthread_join(counting1,NULL);
	pthread_join(counting2,NULL);
	
	pthread_mutex_destroy(&lock);
	return 0;
}
