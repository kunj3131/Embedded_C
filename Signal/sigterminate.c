#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void dumpCore(int sig){
	printf("\n%d signal recieved\n",sig);
	exit(0);
}

int main(){
	signal(SIGQUIT,dumpCore);

	printf("waitin for Quit Signal\n");
	while(1){
		pause();
	}

	return 0;
}
