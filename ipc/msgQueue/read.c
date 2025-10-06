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
        struct msg mess;
	key_t key;
	key = ftok("/tmp/msgqueue_key",65);
	int msgid = msgget(key,0666|IPC_CREAT);
	msgrcv(msgid,&mess,sizeof(mess.msgText),1,0);
	printf("Recieved Message: %s\n",mess.msgText);
	msgctl(msgid,IPC_RMID,NULL);

        return 0;
}

