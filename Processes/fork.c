#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	printf("parent process id: %d\n",getpid());
	pid_t pid = fork();
	if(pid==0){
		printf("child-->Parent Process %d Child  id:%d\n",getppid(),getpid());
		sleep(5);
		printf("child-->Parent Process %d Child  id:%d\n",getppid(),getpid());
	}
	else if(pid>0){
		sleep(2);
		printf("parent-->Parent Process id: %d Child Process ID: %d\n",getpid(),getppid());
	}
	return 0;
}
