#include <stdio.h>

#define MAXLEN 1024

void squeeze(char s[], int c)
{
  int i, j;
  
  for (i = j = 0; s[i] != '\0'; i++) {
    if (s[i] != c)
      s[j++] = s[i];
  }
  s[j] = '\0';
}

int main()
{
  char entry[] = "hello eternity";
  char token = 'e';
  
  printf("String is '%s' and token is '%c'.\n", entry, token);
  squeeze(entry, token);
  printf("%s\n", entry);
  
  return 0;
}
