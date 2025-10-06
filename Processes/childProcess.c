#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	printf("Child Process %d\n",getpid());
	for(int i=0;i<3;i++){
		printf("Hello world\n");
		sleep(2);
		printf("Hi\n");
	}
	printf("Child process completed... Now exiting from Child Process %d\n",getpid());
	exit(1);
	return 0;
}
