#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>

mqd_t mq;
struct mq_attr attr;

void handler(int signo) {
    char buffer[1024];
    while(1){

    mq_receive(mq, buffer, sizeof(buffer), NULL);
    printf("Received: %s\n", buffer);
    }
    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGUSR1;
    mq_notify(mq, &sev);
}

int main() {
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 1024;
    attr.mq_curmsgs = 0;

    mq_unlink("/hello");
    mq = mq_open("/hello", O_CREAT | O_RDONLY, 0666, &attr);

    signal(SIGUSR1, handler);
    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGUSR1;
    mq_notify(mq, &sev);

    while (1) {
        pause();
    }

    mq_close(mq);
    mq_unlink("/hello");
    return 0;
}

