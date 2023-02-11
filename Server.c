// server side
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/errno.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024

int main(void) {
	int sockfd;
	char buffer[MAXLINE];
	const char *hi = "Hi Richard";
	struct sockaddr_in serveraddr, clientaddr;

	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0))<0){
	    exit(EXIT_FAILURE);
	}

	memset(&serveraddr, 0, sizeof(serveraddr));
	memset(&clientaddr, 0, sizeof(clientaddr));

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	serveraddr.sin_port = htons(PORT);

	if(bind(sockfd, (const struct sockaddr *)&serveraddr,sizeof(serveraddr)) < 0)
	{
	    exit(EXIT_FAILURE);
	}
    while(1){
	    socklen_t len;
	    int n;

	    len = sizeof(clientaddr);

	    n = recvfrom(sockfd, (char*)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *) &clientaddr, &len);
	    buffer[n] = '\0';
	    printf("Client : %s\n", buffer);  //echo
	    sendto(sockfd, (const char*)hi, strlen(hi), MSG_CONFIRM, (const struct sockaddr *) &clientaddr, len);
	    printf("Hi Richard sent.\n");
    }
	
    close(sockfd);
	return 0;
}

