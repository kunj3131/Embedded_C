/*
 *
 *	Title: Multi-Level Pipe & Signal Chain Problem
 *
 *	Description: -> Parent fork a child. -> Child forks a Grandchild. -> Each process is connected via pipes: parent -> child -> grandchild
 *	-> Parent sends a data; Grandchild reverse it and sends it back to parent
 *	-> If any process dies, others recieve SIGCHLD and exit.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>

int pipeData[2];
char str[] = "Hello";
char recv[10];

void signalHandler(int sig){
	if(sig == SIGCHLD){
		printf("SIGCHLD recieved\n");
	}
}

int main(){
	pipe(pipeData);
	pid_t pid,pid1;
	signal(SIGCHLD, signalHandler);
	printf("Parent Process %d\n",getpid());
	pid = fork();	
	if(pid > 0){
		write(pipeData[1],&str,sizeof(str));
		printf("Send data: %s\n",str);
		wait(NULL);
		read(pipeData[0],&recv,sizeof(recv));
		printf("recieve Data: %s\n",recv);
		close(pipeData[1]);
		close(pipeData[0]);
		exit(0);	
	}
	if(pid == 0){
                printf("Child Process %d\n",getpid());
                pid1 = fork();
                if(pid1==0){
                        printf("Grand Child Process %d\n",getpid());
                        int status;
                        wait(&status);
                        read(pipeData[0],&recv,sizeof(recv));
                        close(pipeData[0]);
                        char reverse[10];
                        int len = strlen(recv);
                        printf("Length: %d\n",len);
                        for(int i=0;i<len;i++){
                                reverse[i] = recv[len-1-i];
                        }
                        printf("Reverse String: %s\n",reverse);
                        write(pipeData[1],&reverse,sizeof(reverse));
                        printf("Send Data by Grand Child %s\n",reverse);
        		close(pipeData[1]);
        		wait(NULL);
		}
	exit(0);
        }
	return 0;
}
