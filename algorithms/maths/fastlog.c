#include <stdio.h>

float fastlog2(float x)
{
  /* MODIFY THIS SECTION */
  // (x-1)*(a*(x-1) + b)/((x-1) + c)
  const float a =   0.338953;
  const float b =   2.198599;
  const float c =   1.523692;
  #define FN fexp + signif*(a*signif + b)/(signif + c)
  /* END SECTION */
  
  float signif, fexp;
  int exp;
  float lg2;
  union { float f; unsigned int i; } ux1, ux2;
  int greater; // really a boolean
  
  /* Assume IEEE representation, which is 
   *   sgn(1):exp(8):frac(23)
   * representing (1+frac)*2^(exp-127). Call 1+frac the significand
  */
  
  // get exponent
  ux1.f = x;
  exp = (ux1.i & 0x7F800000) >> 23;
  // actual exponent is exp-127, will subtract 127 later
  
  greater = ux1.i & 0x00400000; // true if signif > 1.5
  if (greater) {
    // signif >= 1.5 so need to divide by 2. Accomplish this by
    // stuffing exp = 126 which corresponds to an exponent of -1
    ux2.i = (ux1.i & 0x007FFFFF) | 0x3f000000;
    signif = ux2.f;
    fexp = exp - 126;    // 126 instead of 127 compensates for division by 2
    lg2 = FN;
  } else {
      // get signif by stuffing exp = 127 which corresponds to an exponent of 0
      ux2.i = (ux1.i & 0x007FFFFF) | 0x3f800000;
      signif = ux2.f;
      fexp = exp - 127;
      lg2 = FN;
  }
  // last two lines of each branch are common code, but optimize better
  // when using gcc (test this)
  return(lg2);
}

int main()
{
  printf("fastlog of 16 is %f\n", fastlog2(16));

  return 0;
}
