#include <stdio.h>

# this algorithm is far too slow
int main()
{
  long dividend = 600851475143;
  int divisor = 2, result;

  while (1)
  {
    printf("%d\n%", divisor);
    int quotient = dividend / divisor;
    int remainder = dividend % divisor;
    if (quotient == 1)
    {
      result = quotient;
      break;
    }
    if (remainder == 0)
    {
      dividend = quotient;
      continue;
    }
    else
    {
      divisor++;
    }
  }

  printf("%d", result);
}
