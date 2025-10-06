/*
 *	Program Title: Pipe Creation and Communication between Parent and Child
 *
 * 	Description: This program demonstrates IPC using two pipes between parent child(One side Communication-Commented Section) 
 *	in that Tried to develop full-duplex communication(Parent and Child both can transmit and send a data) using two pipes.
 *
 */


#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int pipeData[2],pipe2Data[2];
	pid_t pid;
	char sentMsg[]="Hello World";
	char recvMsg[20];

	if(pipe(pipeData) == -1 || pipe(pipe2Data) == -1){
		printf("Pipe is not created\n");
	}

	pid = fork();
	
	if(pid==0){
//		write(pipeData[1],sentMsg,sizeof(sentMsg));	
//		read(pipeData[0],recvMsg,sizeof(recvMsg));
//		printf("Child Sent %d: %s\n",getpid(),sentMsg);
//		printf("Child Recieved %d: %s\n",getpid(),recvMsg);
//		close(pipeData[1]);
//
		close(pipeData[0]);
		close(pipe2Data[1]);
        	write(pipeData[1],sentMsg,sizeof(sentMsg));
        	printf("Child Sent %d: %s\n",getpid(),sentMsg);
		read(pipe2Data[0],recvMsg,sizeof(recvMsg));
        	printf("Child recieve %d: %s\n",getpid(),recvMsg);
		close(pipeData[1]);
		close(pipe2Data[0]);
	}
	else if(pid>0){
//		read(pipeData[0],recvMsg,sizeof(recvMsg));
//		printf("Process Recieved %d: %s\n",getpid(),recvMsg);
//		close(pipeData[0]);
//		close(pipeData[1]);
	
		close(pipeData[1]);
		close(pipe2Data[0]);
	       	read(pipeData[0],recvMsg,sizeof(recvMsg));
	       	printf("Process Recieved %d: %s\n",getpid(),recvMsg);
 	       	write(pipe2Data[1],recvMsg,sizeof(sentMsg));
	       	printf("Process sent %d: %s\n",getpid(),sentMsg);
		close(pipeData[0]);
		close(pipe2Data[1]);	
	}

	return 0;
}

