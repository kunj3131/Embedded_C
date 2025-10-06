#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct mesg{
	long msgtype;
	char msg[100];
};

int main(){
	key_t key;
	key = ftok("sys/msgqueue_key",65);
	int msgid = msgget(key,0666|IPC_CREAT);
	struct mesg mes;
	mes.msgtype = 1;
	strcpy(mes.msg, "Hello World");
	msgsnd(msgid,&mes,sizeof(mes.msg),0);
	printf("Message sent: %s\n",mes.msg);

	msgrcv(msgid,&mes,sizeof(mes.msg),1,0);
	printf("Rx msg: %s\n",mes.msg);
	msgctl(msgid,IPC_RMID,NULL);
	return 0;
}
