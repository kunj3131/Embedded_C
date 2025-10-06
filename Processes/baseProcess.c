/*
 *
 *	Title: Base Program to create child process from parent process using fork() system call
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	printf("Parent Process id:%d\n",getpid());

	pid_t pid = fork();
	if(pid == 0){
		sleep(20);
		printf("Child Process id: %d Parent Process id: %d\n",getpid(),getppid());
	
	}
	else if(pid>0){
		sleep(20);
		printf("Parent Process: %d\n",getpid());
	}


	return 0;
}
