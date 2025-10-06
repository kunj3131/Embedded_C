#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <sys/signal.h>

void sigTerm(int sig){
	printf("%d signal recieved\n",sig);
	exit(1);
}

int main(){
	signal(SIGQUIT,NULL);
	printf("Parent Process ID: %d\n",getpid());
	pid_t pid = vfork();
	if(pid==0){
		printf("\n000000000000000000000000000000000000000000\n");
		printf("Child Process id Created\n Child Process Id: %d Parent Process ID: %d\n",getpid(),getppid());
		pid_t cpid = vfork();
		if(cpid == 0){
			if(setpriority(PRIO_PROCESS,0,-15)==-1){
				perror("Not set\n");
			}
			printf("\n111111111111111111111111111111111111111111111\n");
			printf("Child's Child Process is Created\n Child's Child Process ID: %d and Child Process ID: %d\n",getpid(),getppid());
			for(int i=0;i<10;i++){
				printf("Jr. Child\n");
				sleep(1);
			}
			raise(SIGTERM);
		}
		else if(cpid > 0){
//			int status;
			if(setpriority(PRIO_PROCESS,0,-10)==-1){
				perror("Not set\n");	
			}
//			wait(&status);
			printf("\n22222222222222222222222222222222222222222222222\n");
			printf("Return to Child Process which id is %d\n",getpid());
			for(int i=0;i<5;i++){
				printf("Child Process\n");
				sleep(1);
			}
			raise(SIGTERM);
		}
		raise(SIGTERM);
	}
	else if(pid>0){
		if(setpriority(PRIO_PROCESS,0,-20)==-1){
			perror("Not set\n");
		}
//		int status;
//		wait(&status);
		printf("\n33333333333333333333333333333333333333333333333333333333333\n");
		for(int i=0;i<3;i++){
			printf("Parent Process\n");
			sleep(1);
		}
		raise(SIGTERM);
	}
	return 0;
}
