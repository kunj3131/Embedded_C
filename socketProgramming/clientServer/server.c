#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(){
	struct sockaddr_in socketAddress, clientAddress;

/*
 *	Socket Creation
 */

	int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(sock < 0){
		printf("Socket creation Failed\n");
		return 1;
	}
	printf("Socket is Created\n");

 /*
 *	Set Socket for Reuse
 */
	int sendbuff =20;
	if(setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&sendbuff,sizeof(sendbuff))<0){
		printf("Error\n");
	}

 /*
 *	Socket Binding
 */

	socketAddress.sin_family = AF_INET;
	socketAddress.sin_port = htons(7);
	socketAddress.sin_addr.s_addr = INADDR_ANY;

	if(bind(sock,(struct sockaddr*)&socketAddress,sizeof(socketAddress))<0){
		printf("Binding Failed\n");
		return 1;
	}
	printf("Binding Successful\n");

/*
 *	Listening
 */

	if(listen(sock,1)<0){
		printf("Listening Failed\n");
		return 1;
	}
	printf("Listening successful\n");

/*
 *	Accept
 */

	socklen_t clientAddressSize = sizeof(clientAddress);
	int clientSock = accept(sock,(struct sockaddr*)&clientAddress,&clientAddressSize);
	if(clientSock < 0){
		printf("Accept Failed\n");
		return 1;
	}
	printf("Client Connected\n");
	
/*
 *	Receive
 */

	char buffer[20];
	int len = recv(clientSock,buffer,sizeof(buffer)-1,0);
	if(len<0){
		printf("Recieved Failed\n");
		return 1;
	}

	buffer[len] = '\0';
	printf("Recieved Message: %s\n",buffer);

/*
 *	Send
 */
	char sendBuffer[20]="Helllo socket";
	int Leng=sizeof(sendBuffer);
	if(send(clientSock,sendBuffer,Leng,0)<0){
		printf("Sending Failed\n");
		return 1;
	}
	printf("Msg sent\n");

/*
 */


/*
 *	Close socket
 */

	close(clientSock);
	close(sock);

	return 0;

}
