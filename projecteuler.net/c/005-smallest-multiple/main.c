// https://projecteuler.net/problem=5

#include <stdio.h>

int main()
{
  int num, count = 1;

  while (1)
  {
    int numFound = 1;

    num = 20 * count++;
    for (int i = 1; i < 20; i++)
      if (num % i != 0) numFound = 0;

    if (numFound)
    {
      printf("%d\n", num);
      return 0;
    }
  }
}
