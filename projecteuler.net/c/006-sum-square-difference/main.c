#include <stdio.h>

int main()
{
  int sumSquares = 0, squareSum = 0;
  for (int count = 1; count <= 100; count++)
  {
    sumSquares += (count * count);
    squareSum += count;
  }

  squareSum *= squareSum;
  printf("%d\n", squareSum - sumSquares);
}
