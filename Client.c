// Client side
#include <unistd.h>
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

int main() {
	int sockfd;
	char buffer[MAXLINE];
	const char *hi = "Hi Mr. Mr.";
	struct sockaddr_in serveraddr;
	const int max_interval = 8, m = 2;
	const double base = 0.5;
	int retry = 0; 
	double interval = base * pow(m, retry);


	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
    	interval = base * pow(m, retry++);
    	if(interval < max_interval)
    	{
    		sleep(interval);
    	}
    	else
    	{
    		return 1;
    	}
	}

	memset(&serveraddr, 0, sizeof(serveraddr));

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = INADDR_ANY;

    int n;
    socklen_t len;
       
    sendto(sockfd, (const char *)hi, strlen(hi),
        MSG_CONFIRM, (const struct sockaddr *) &serveraddr, 
            sizeof(serveraddr));
    printf("Hi Mr. Mr. sent.\n");;
           
    n = recvfrom(sockfd, (char *)buffer, MAXLINE, 
                MSG_WAITALL, (struct sockaddr *) &serveraddr,
                &len);
    buffer[n] = '\0';
    printf("Server : %s\n",buffer);  // echo
   
    close(sockfd);
    return 0;
}
