#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void sigchild(int sig){
	printf("%d signal is generated\n",sig);
	int status;
	pid_t pid;
	while((pid = waitpid(-1,&status,WNOHANG))>0){
		printf("Chile process %d terminated\n",pid);
	}
}

void signINT(int sig){
	if(sig == 2){
		printf("%d Exit child process\n",sig);
		exit(0);
	}
}	

int main(){
	signal(SIGCHLD, sigchild);
	pid_t pid = fork();
	if(pid==0){
		printf("%d child processid\n",getpid());
		signal(SIGINT,signINT);
		while(1){
			pause();
		}
		printf("Child process closed\n");
	}
	else{
		signal(SIGINT, SIG_IGN);
		printf("%d parent processid\n",getpid());
		sleep(5);
		printf("Parent Process terminated\n");
	}

	return 0;
}
