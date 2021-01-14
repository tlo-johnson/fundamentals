#include <stdio.h>

int isDivisible(int prime, int divisor);
int primeFound(int num, int divisor);

int main()
{
  int position = 10001;

  // 2 is prime
  int result = 2;
  position--;

  // 3 is also prime
  if (position-- > 0)
    result = 3;

  int num = 5;
  for (; position > 0; position--)
  {
    // skip all even numbers
    for (; ; num += 2)
    {
      for (int divisor = 3; !isDivisible(num, divisor); divisor++)
      {
        if (!primeFound(num, divisor))
          continue;

        result = num;
        num += 2;
        goto findNextPrime;
      }
    }
findNextPrime:
    ;
  }

  printf("%d\n", result);
}

int isDivisible(int num, int divisor)
{
  return num % divisor == 0;
}

int primeFound(int num, int divisor)
{
  return num / divisor < 2;
}
