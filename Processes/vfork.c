#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	printf("parent process if: %d\n",getpid());
	pid_t pid = vfork();
	if(pid == 0){
		printf("Child--> Parent process id: %d child process id: %d\n",getppid(),getpid());
		exit(1);
	}
	else if(pid > 0){
		printf("Parent--> Parent process id: %d Child process id: %d\n",getpid(),pid);
	}

	return 0;
}
