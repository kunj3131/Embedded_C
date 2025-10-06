#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void signa(int sig){
	printf("Exit\n");
	exit(1);
}

int main(){
	printf("Parent Process ID: %d\n",getpid());
	pid_t pid = fork();
	if(pid == 0){
		printf("Child Process ID: %d\n",getpid());
		signal(SIGINT,signa);
		while(1){
			sleep(1);
		}
	}	
	else if(pid>0){
		printf("Parent Process %d child Process %d\n",getpid(),pid);
		wait(NULL);
		printf("Signal is generated\n");
	}
}
