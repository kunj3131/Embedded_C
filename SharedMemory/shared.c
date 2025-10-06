#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

int main(){
	key_t key = ftok("shmfile",65);
	int id = shmget(key,1024,0666 | IPC_CREAT);

	pid_t pid = vfork();

	if(pid == 0){
		char *data;
		data = (char *) shmat(id, NULL, 0);

		strcpy(data,"Hello world");
		shmdt(data);
		printf("Data saved: %s\n",data);
	}

	else if(pid > 0){
		char *data;
		printf("Read: %s\n",data);
		shmdt(data);
		shmctl(id, IPC_RMID, NULL);

	}

	return 0;
}
