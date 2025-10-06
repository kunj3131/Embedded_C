#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void signaling(int sig){
	while(1){
		printf("Hello the value is:  %d\n",sig);
		exit(sig);
	}
}

int main(){
	//signal(SIGINT,signaling);
	signal(SIGTSTP, signaling);
	pid_t pid = getpid();
	printf("%lu\n",pid);
//	kill(pid,SIGINT);
	kill(pid, SIGTSTP);
	return 0;
}
