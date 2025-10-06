/*
 *	Title: Basic Parent Child Communication using PIPE in IPC
 *
 *	Description: Parallel execution of parent process and Child process
 *
 *
 */


#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int pipeq[2];
char sendData[] = "Hello world from parent";
char sendData1[] = "Hello World from Child";
char recv[50];

int main(){
	if(pipe(pipeq)==-1){
		printf("Error\n");
	}
	printf("Parent process %d\n",getpid());
	write(pipeq[1],&sendData,sizeof(sendData));
	printf("Send data: %s\n",sendData);
	pid_t pid = fork();
	if(pid == 0){
		write(pipeq[1],&sendData1,sizeof(sendData1));
		printf("sent data by child: %s\n",sendData1);
		close(pipeq[1]);
		read(pipeq[0],&recv,sizeof(recv));
		printf("Read Data by Child: %s\n",recv);
		close(pipeq[0]);
	}
	else if(pid>0){
		read(pipeq[0],&recv,sizeof(recv));
		printf("Read Data: %s\n",recv);
		close(pipeq[0]);
	}
	return 0;
}
