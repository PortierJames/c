#include <stdio.h>

int gcd(int a, int b)
{
  int t;

  do {
    if (a < b) {
      t = a;
      a = b;
      b = t;
    }
    a = a - b;
  } while (a > 0);
  
  return b;
}
  

int main(void)
{
  int x, y;
  int d;
	
  printf("Please enter two integers: ");
  scanf("%d", &x);
  scanf("%d", &y);
	
  if (x > 0 && y > 0) {
    d = gcd(x, y);
    printf("The greatest common divisor of %d and %d is %d.\n", x, y, d);
  }
  else
    printf("Okay, I really meant two positive natural numbers. Try again!\n");
	
  return 0;
}
