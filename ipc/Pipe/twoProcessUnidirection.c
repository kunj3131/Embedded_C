/*
 *	Title: Simple Parent-Child Communication using a Single Pipe in c
 *
 *	Description: This program Demonstrates basic IPC between a Parent and Child process usin a single pipe. It shows sequential message exchange between process synchronization
 *
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int pipeq[2];
char sendData[]="Hello From Parent";
char sendData1[] = "Hello from Child 1";
char recv[50];

int main(){
        printf("Parent PRocess: %d\n",getpid());
        if(pipe(pipeq)==-1){
                printf("error\n");
        }

	write(pipeq[1],&sendData,sizeof(sendData));
        printf("parent sent: %s\n",sendData);
        pid_t pid= fork();
        if(pid == 0){
             //   close(pipeq[1]);
                read(pipeq[0],&recv,sizeof(recv));
                printf("Child recv: %s\n",recv);
                close(pipeq[0]);
                write(pipeq[1],&sendData1,sizeof(sendData1));
                printf("child send: %s\n",sendData1);
                close(pipeq[1]);
        }
        else if(pid > 0){
        	wait(NULL);
                read(pipeq[0],&recv,sizeof(recv));
                printf("Parent recv: %s\n",recv);
                close(pipeq[0]);
        }
        return 0;
}
