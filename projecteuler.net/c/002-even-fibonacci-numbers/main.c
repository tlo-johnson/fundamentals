#include <stdio.h>

int main()
{
  int prev = 1, curr = 2, total = curr, max = 4000000;
  while (curr < max)
  {
    int temp = curr;
    curr = prev + curr;
    prev = temp;

    if (curr % 2 == 0)
      total += curr;
  }

  printf("%u\n", total);
}
