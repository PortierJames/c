#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, portno;

    if (argc < 2) {
      fprintf(stderr, "ERROR, no port provided\n");
      exit(1);
    }
    
    portno = atoi(argv[1]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
      error("ERROR opening socket");
    
    return 0;
}
