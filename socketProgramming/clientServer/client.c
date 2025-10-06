#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(){
        struct sockaddr_in serverAddress;
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port = htons(8080);

	char str[] = "127.0.0.1";
        if (inet_pton(AF_INET, str, &serverAddress.sin_addr) <= 0) {
        printf("Invalid address / Address not supported\n");
        return 1;
        }


        int sock;
        sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
        if(sock==-1){
                printf("Failed to create a socket\n");
                return 1;
        }
        printf("Socket Created\n");

        if(connect(sock,(struct sockaddr *)&serverAddress,sizeof(serverAddress))<0){
                printf("Connection Failed\n");
                return 1;
        }
        printf("Connection Created\n");

        char message[20];
        strcpy(message,"Welcome to server");
        if(send(sock,message,strlen(message),0)<0){
                printf("Sending Failed\n");
                return 1;
        }
 	printf("sent message %s\n",message);
	 
	char reply[20];
        int len = recv(sock,reply,sizeof(reply)-1,0);

        if(len<0){
                printf("Recieve Failed\n");
                return 1;
        }
        reply[len] = '\0';
        printf("recieve Message: %s\n",reply);

        close(sock);
        return 0;
}

