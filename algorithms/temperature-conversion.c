#include <stdio.h>

int main()
{
  float cels, fahr;
  int lower, upper, step;
  
  lower = -100;
  upper = 200;
  step = 20;
  
  cels = lower;
  
  printf("CELSIUS  |  FAHRENHEIT\n");	  
  while (cels <= upper) {
    fahr = ((9.0/5.0) * cels) + 32.0;
    printf(" %6.0f  |  %6.1f\n", cels, fahr);
    cels += step;
  }
  
  return 0;

}
