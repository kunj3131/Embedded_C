#include <stdio.h>
#include <pthread.h>

int maxCount = 0;
int Count = 10000000;
void *count(){
		for(int i=0;i<Count;i++){
			maxCount++;
		}
		pthread_t threadID = pthread_self();
		printf("%d of thredID %lu\n",maxCount,threadID);
}

int main(){
	pthread_t counting1, counting2;
	pthread_create(&counting1,NULL,count,NULL);
	pthread_create(&counting2, NULL,count,NULL);
	pthread_join(counting1,NULL);
	pthread_join(counting2,NULL);
	return 0;
}
