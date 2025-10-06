#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main(){
	printf("Parent ID: %d\n",getpid());
	pid_t pid = fork();
	if(pid==0){
		printf("Child Process ID: %d\n",getpid());
		signal(SIGTERM,NULL);
		printf("Child PRocess end");
		pause();
	}
	else if(pid>0){
		printf("Parent Process id: %d\n",getpid());
		sleep(1);
		printf("Child Process terminared: %d\n",pid);
		kill(pid,SIGTERM);
		wait(NULL);
		printf("Closed\n");	
	}
	return 0;
}
