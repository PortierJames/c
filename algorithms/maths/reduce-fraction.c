#include <stdio.h>

struct frac {
	int a;
	int b;
	};

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

struct frac reduce(struct frac unfrac)
{
  int x, y;
  x = unfrac.a;
  y = unfrac.b;
  
  if (gcd(x, y) == 1) {
    return unfrac;
  } else {
    unfrac.a = unfrac.a / gcd(x, y);
    unfrac.b = unfrac.b / gcd(x, y);
    return unfrac;
  }
}

int main()
{
	
	int num;
	int den;
	
	printf("Please enter the numerator: \n");
	scanf("%d", &num);
	printf("Please enter the denominator: \n");
	scanf("%d", &den);
	
	struct frac ufrac = {num, den};
	ufrac = reduce(ufrac);
	
	printf("The reduced fraction is %d/%d.\n", ufrac.a, ufrac.b);
	
	return 0;
}
