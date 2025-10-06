#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
	int x=10;
	pid_t pid = vfork();
	if(pid==0){
		x+=5;
		printf("child -- > %d\n",x);
		exit(1);
	}
	else if(pid>0){
		wait(NULL);
		printf("parent -- > %d\n",x);
	}
}
