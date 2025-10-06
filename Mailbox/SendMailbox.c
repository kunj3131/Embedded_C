/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    mqd_t mq;
    struct mq_attr attr;
    char buffer[1024];

    // Define mailbox attributes
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 1024;
    attr.mq_curmsgs = 0;

    // Create a message queue (mailbox)
    mq = mq_open("/my_mailbox", O_CREAT | O_WRONLY, 0644, &attr);
    if (mq == -1) {
        perror("mq_open");
        exit(1);
    }

    // Send a message to the mailbox
    strcpy(buffer, "Hello from producer!");
    if (mq_send(mq, buffer, strlen(buffer) + 1, 0) == -1) {
        perror("mq_send");
        exit(1);
    }

    printf("Message sent to mailbox.\n");

    mq_close(mq);
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
	mqd_t mq;
	struct mq_attr attr;
	attr.mq_flags = 0;	// 0: Blocking O_NONBLOCKING: Non Blocking
	attr.mq_maxmsg = 3;
	attr.mq_msgsize = 1024;
	attr.mq_curmsgs = 0;
	mq = mq_open("/hello", O_CREAT | O_WRONLY, 0644, &attr);
	char buffer[27];

	strcpy(buffer, "Hello World");
	mq_send(mq,buffer,strlen(buffer)+1,0);
	printf("sent :%s\n",buffer);
	strcpy(buffer, "Hello from Producer");
	mq_send(mq,buffer,strlen(buffer)+1,0);
	printf("sent :%s\n",buffer);
	strcpy(buffer, "Hello from Producer 2");
	mq_send(mq,buffer,strlen(buffer)+1,0);
	printf("sent :%s\n",buffer);
	mq_close(mq);

	return 0;
}	

