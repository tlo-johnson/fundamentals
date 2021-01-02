#include <stdio.h>
#include <math.h>

// solution stolen from: https://www.geeksforgeeks.org/find-largest-prime-factor-number/

int main()
{
  long dividend = 600851475143;
  int result = 0;
  int maxDivisor = sqrt(dividend);

  for (long divisor = 3; divisor <= maxDivisor; divisor += 2)
    while (dividend % divisor == 0)
    {
      result = divisor;
      dividend /= divisor;
    }

  printf("result: %d\n", result);
}
