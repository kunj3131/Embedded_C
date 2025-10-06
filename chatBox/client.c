#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// Socket Programming
#include <arpa/inet.h>
#include <sys/socket.h>

int main(){
	struct sockaddr_in socketAddress;

        socketAddress.sin_family = AF_INET;
        socketAddress.sin_port = htons(8080); // 7 port for echo server on same host machine
	
	char strIPAddr[17];
	printf("Enter IP Address: \n");
	scanf("%s",strIPAddr);	
	getchar();

	if(inet_pton(AF_INET, strIPAddr, &socketAddress.sin_addr) <= 0){
		printf("Invalid Address / Address not supported\n");
		return 1;
	}

	int sock = socket(AF_INET, SOCK_STREAM,IPPROTO_TCP);
	if(sock == -1){
		printf("Failed to create a socket\n");
		return 1;
	}
	printf("Socket Created\n");

	if(connect(sock, (struct sockaddr *)&socketAddress, sizeof(socketAddress))<0){
		printf("Connection Failed\n");
		return 1;
	}
	printf("Connection Created\n");
	
	char message[1024];
	printf("Enter Message\n");
	if(fgets(message, sizeof(message), stdin) != NULL){
		message[strcspn(message, "\n")] = '\0';
		printf("%s\n",message);
	}

	if(send(sock, message, strlen(message),0)<0){
		printf("Sending Failed\n");
		return 1;
	}
	printf("Sent Message %s\n", message);

	char reply[1024];
	int len = recv(sock, reply, sizeof(reply),0);
	if(len<0){
		printf("Recieve Failed\n");
		return 1;
	}
	reply[len] = '\0';
	printf("Recieve Message: %s\n", reply);
	
	close(sock);
	return 0;
}
