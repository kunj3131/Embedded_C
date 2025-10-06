#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg{
	long msgType;
	char msgText[100];
};

int main(){
	key_t key;
	int msgId;
	key = ftok("/tmp/msgqueue_key",65);
	msgId = msgget(key,0666|IPC_CREAT);	
	struct msg mess;
	mess.msgType = 1;
	strcpy(mess.msgText,"Hello World");
	msgsnd(msgId,&mess,sizeof(mess.msgText),0);
	printf("Message sent: %s\n",mess.msgText);
	
	return 0;
}
