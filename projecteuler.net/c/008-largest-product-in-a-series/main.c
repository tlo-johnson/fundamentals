#include <stdio.h>
#include <stdlib.h>

int getInitialProduct();

int main()
{
  int numDigits = 4;
  int product = 0;
  FILE *ptr = fopen("input.txt", "r");

  product = getInitialProduct(ptr, numDigits);
  printf("%d\n", product);

  fclose(ptr);

  return 0;
}

int getInitialProduct(FILE *ptr, int numDigits)
{
  int num = 1;
  while (numDigits-- > 0)
  {
    char value;
    fscanf(ptr, "%c", &value);
    num *= (value - 48); // convert char to decimal in utf8 char set
  }

  return num;
}
