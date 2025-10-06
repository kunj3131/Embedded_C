#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sema;

void *counting(){
	int count = 0;
	printf("Critical Section Start\n");
	sem_wait(&sema);
	count++;
	sleep(2);
	printf("%d\n",count);
	sem_post(&sema);
	printf("Critical Section End\n");
}

int main(){
	pthread_t thread1,thread2,thread3;

	sem_init(&sema,0,3);
	pthread_create(&thread1,NULL,counting,NULL);
	pthread_create(&thread2,NULL,counting,NULL);
	pthread_create(&thread3,NULL,counting,NULL);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_join(thread3,NULL);

	sem_destroy(&sema);

	return 0;
}
