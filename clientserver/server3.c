#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int portno;

    if (argc < 2) {
      fprintf(stderr, "ERROR, no port provided\n");
      exit(1);
    }
    
    portno = atoi(argv[1]);
    
    return 0;
}
