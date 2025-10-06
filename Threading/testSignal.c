#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig(int sig){
	if(sig==SIGINT){
		while(1){
	printf("Hello\n");
		}
	return;
	}
	printf("quit the process\n");
	exit(EXIT_SUCCESS);
}

int main(){
	signal(SIGINT,sig);
	signal(SIGQUIT,sig);
	for(int i=0;;i++){
		printf("%d\n",i);
		sleep(2);
	}
	return 0;
}

