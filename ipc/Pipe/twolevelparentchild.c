/*
 *	Title: Multi-Level Process Communication via a Single Pipe in C
 *
 * 	Description: This C program uses fork() to create a parent, child, and grandchild process, all communicating through a single unidirectional pipe. It demonstrates process hierarchy and message passing between generations.
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int pipeq[2];
char sendData[]="Hello From Parent";
char sendData1[] = "Hello from Child 1";
char sendData2[] = "Hello from Child 2";
char recv[50];

int main(){
	printf("Parent PRocess: %d\n",getpid());
	if(pipe(pipeq)==-1){
		printf("error\n");
	}
	
	write(pipeq[1],&sendData,sizeof(sendData));
	printf("Parent sent: %s\n",sendData);
	pid_t pid = fork();
	if(pid == 0){
	//	close(pipeq[1]);
		read(pipeq[0],&recv,sizeof(recv));
		printf("Child recv: %s\n",recv);
	//	close(pipeq[0]);
		
		pid_t pidc1 = fork();
	       	if(pidc1 == 0){	
			write(pipeq[1],&sendData1,sizeof(sendData1));
			printf("child's child send: %s\n",sendData1);
			close(pipeq[1]);

			read(pipeq[0],&recv,sizeof(recv));
			printf("Child's child recv: %s\n",recv);
			close(pipeq[0]);
		}
		else if(pidc1>0){
			wait(NULL);
			write(pipeq[1],&sendData2,sizeof(sendData2));
			printf("child send: %s\n",sendData2);
			close(pipeq[1]);
		}
	}
	else if(pid > 0){
		wait(NULL);
		read(pipeq[0],&recv,sizeof(recv));
		printf("Parent recv: %s\n",recv);
		close(pipeq[0]);
	}
	return 0;
}
