/* Shell Version 1 

Notes:
- you can exit from this program with ctrl-d
- to add built in comments like cd or exit, you have
  to tokenize the line using strtok() and look at the first token

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

int main(int argc, char *argv[]) {
	char line[MAX_LENGTH];
	
	while(1) {
		printf("> ");
		if (!fgets(line, MAX_LENGTH, stdin)) break;
		system(line);
		}
		
		return 0;
		
}
