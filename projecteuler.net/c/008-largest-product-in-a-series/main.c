#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char getDigit(FILE *ptr)
{
  char value;
  fscanf(ptr, "%c", &value);
  return value;
}

void getNum(FILE *fptr, char num[], int size)
{
  for (int count = 0; count < size; count++)
    num[count] = getDigit(fptr);
  num[size] = '\0';
}

unsigned long int getProduct(char num[], int size)
{
  unsigned long int product = 1;
  while (--size >= 0)
    product *= num[size] - 48;
  return product;
}

void slideWindow(char num[], int size, char digit)
{
  for (int count = 0; count < size; count++)
    num[count] = (count == size - 1) ? digit : num[count + 1];
}

int main()
{
  int numDigits = 13;
  char num[numDigits + 1];
  FILE *fptr = fopen("input.txt", "r");

  getNum(fptr, num, numDigits);
  unsigned long int largestProduct = getProduct(num, numDigits);

  char digit;
  while ((digit = getDigit(fptr)) != '\n')
  {
    slideWindow(num, numDigits, digit);
    unsigned long int product = getProduct(num, numDigits);
    if (product > largestProduct)
      largestProduct = product;
  }

  printf("%lu\n", largestProduct);
  fclose(fptr);
  return 0;
}
