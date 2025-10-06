#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void signalHand(int sig){
	printf("Signal val %d:\n",sig);
	exit(sig);
}

void *printing(){
	while(1){
		int count=0;
		printf("Hello World\n");
		count++;
		if(count == 5)
			raise(SIGINT);
	}
}

int main(){

	pthread_t signaling;
	int count =0;
	signal(SIGINT, signalHand);
	pthread_create(&signaling, NULL, printing, NULL);
	pthread_join(signaling, NULL);
	pid_t pid = getpid();
	kill(pid,SIGINT);

	return 0;
}
