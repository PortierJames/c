#include <stdio.h>

#define MAX 256

void sort(int array[])
{
  int i, j, temp;
  int len = sizeof(array);
 
  for (i = 0; i < len; i++) {
    for (j = 0; j < (len - i); j++) {
      if (array[j] > array[j+1]) {
        temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }
}

int main(int argc, char *argv[])
{
  int array[5];
  int i;
  
  printf("Enter a list of 5 numbers.\n");
  for (i = 0; i < 5; i++) {
    scanf("%d", &array[i]);
  }  
  
  sort(array);
  
  for (i = 0; i < 5; i++) {
    printf("%d ", array[i]);
  }

  return 0;
}
