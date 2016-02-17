#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, status, portno;
    
    struct sockaddr_in serv_addr;
    struct addrinfo hints;
		struct addrinfo *servinfo;

		memset(&hints, 0, sizeof hints);
		hints.ai_family=AF_UNSPEC;
		hints.ai_socktype=SOCK_STREAM;
		hints.ai_flags=AI_PASSIVE;		

    if (argc < 3) {
      fprintf(stderr, "usage %s hostname port\n", argv[0]);
      exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
      error("ERROR opening socket"); 
    status = getaddrinfo(argv[1], argv[2], &hints, &servinfo);
    if (status != 0) {
      fprintf(stderr, "ERROR no such host\n");
      exit(0);
    }
    
    memset((char *) &serv_addr, '\0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) INADDR_ANY,
            (char *)&serv_addr.sin_addr.s_addr,
            sizeof (INADDR_ANY));
    serv_addr.sin_port = htons(portno);
    
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
      error("ERROR connecting");
    else
      printf("Connection to port %d successful.\n", portno);

    return 0;
}

