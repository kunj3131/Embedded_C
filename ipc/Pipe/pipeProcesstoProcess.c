/*
 *
 *	Title: ipc communication in Process. Same Process send and recieves data from pipe.
 *
 */

#include <stdio.h>
#include <unistd.h>

int main(){
	int pipeData[2],pipe2Data[2];
	char sentMsg[]="Hello World";
	char recvMsg[20];

	if(pipe(pipeData) == -1 | pipe(pipe2Data) == -1){
		printf("Pipe is not created\n");
	}
	
//	read(pipe2Data[0],recvMsg,sizeof(recvMsg));
	write(pipeData[1],sentMsg,sizeof(sentMsg));
	printf("Process Sent %d: %s\n",getpid(),sentMsg);
//	printf("Process recieve %d: %s\n",getpid(),recvMsg);
	
//	write(pipe2Data[1],recvMsg,sizeof(sentMsg));
	read(pipeData[0],recvMsg,sizeof(recvMsg));
//	printf("Process sent %d: %s\n",getpid(),sentMsg);
	printf("Process Recieved %d: %s\n",getpid(),recvMsg);
	
	close(pipe2Data[0]);
	close(pipe2Data[1]);
	close(pipeData[0]);
	close(pipeData[1]);

	return 0;
}
