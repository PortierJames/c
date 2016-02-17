#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int portno;

    if (argc < 3) {
      fprintf(stderr, "usage %s hostname port\n", argv[0]);
      exit(0);
    }

    portno = atoi(argv[2]);
    
    return 0;
}

