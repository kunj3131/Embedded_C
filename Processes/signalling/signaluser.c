#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/signal.h>
#include <sys/wait.h>

void userhandlr(int sig){
	printf("Child recieved %d signal to exit child process ID: %d\n",sig, getpid());
	exit(0);
}

void user2handlr(int sig){
	printf("Child recieved %d signal to exit child process ID: %d\n",sig, getpid());
	exit(0);
}

int main(){
	printf("Parent Process ID: %d\n",getpid());
	pid_t pid = fork();
	if(pid==0){
		printf("Child Process is Created\n Child Process ID: %d Parent Process ID: %d\n",getpid(),getppid());
		signal(SIGUSR1,userhandlr);
		signal(SIGUSR2,user2handlr);
		printf("Child Process exited\n");
		while(1){
			pause();
		}

	}
	else if(pid>0){
		printf("Parent Process Created Child process\t Parent ID: %d, Child ID: %d\n",getpid(),pid);
		sleep(1);
		printf("Send signal to child\n");
		kill(pid,SIGUSR1);
		kill(pid,SIGUSR2);
		wait(NULL);
		printf("Child Process Terminated Now Good Bye!\n");
		exit(0);
	}

	return 0;
}
