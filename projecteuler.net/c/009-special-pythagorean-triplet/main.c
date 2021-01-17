#include <stdio.h>
#include <math.h>

int isInteger(double num)
{
  return ceil(num) == floor(num);
}

int isAnswer(int a, int b, double c)
{
  return a + b == 1000 - c;
}

int displayProduct(int a, int b, double c)
{
  printf("%d\n", a * b * (int) c);
}

int main()
{
  for (int a = 1; ; a++)
  {
    for (int b = 1; ; b++)
    {
      double c = sqrt(pow(a, 2) + pow(b, 2));
      if (c >= 1000) break;
      if (!isInteger(c)) continue;
      if (isAnswer(a, b, c))
      {
        displayProduct(a, b, c);
        return 0;
      }
    }
  }
}
