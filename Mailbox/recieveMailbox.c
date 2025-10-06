/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>
#include <fcntl.h>

int main() {
    mqd_t mq;
    char buffer[1024];

    // Open existing mailbox for reading
    mq = mq_open("/hello", O_RDONLY);
    if (mq == -1) {
        perror("mq_open");
        exit(1);
    }

    // Receive message
    if (mq_receive(mq, buffer, 1024, NULL) == -1) {
        perror("mq_receive");
        exit(1);
    }

    printf("Received message: %s\n", buffer);

    mq_close(mq);
    mq_unlink("/my_mailbox"); // Remove mailbox
    return 0;
}
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <mqueue.h>
#include <fcntl.h>

int main(){
	mqd_t mq;
	struct mq_attr attr;
	char buffer[100];
	mq =  mq_open("/hello", O_RDONLY);
	while(1){
		mq_getattr(mq,&attr);
		if(attr.mq_curmsgs == 0){
			break;
		}
		printf("%ld\n",attr.mq_curmsgs);
		mq_receive(mq, buffer, 1024, NULL);
		printf("recieve %s\n",buffer);
	}
	return 0;
}
