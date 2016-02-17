#include <stdio.h>

int gcd(x, y, z)
{
  int t;
  int t2;
  
  do {
  if (x < y) {
      t = x;
      x = y;
      y = t;
    }
    x = x - y;
  } while (x > 0);
  // y is now gcd(x, y);
  
  do {
  if (y < z) {
    t = y;
    y = z;
    z = t;
    }
    y = y - z;
  } while (y > 0);
  
  return z;
  
}

int main()
{
  int x, y, z;
  int g;
  
  printf("Enter three numbers: \n");
  scanf("%d %d %d", &x, &y, &z);
  
  g = gcd(x, y, z);
  printf("The greatest common denominator of %d %d and %d is %d.\n", x, y, z, g);

  return 0;
}
