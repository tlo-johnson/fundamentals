#include <stdio.h>
#include <string.h>

int isPalindrome(int num)
{
  char str[6];
  sprintf(str, "%d", num);

  for (int len = strlen(str), index = 0; index <= len; len--, index++)
    if (str[len - 1] != str[index]) return 0;

  return 1;
}

int main()
{
  int largestPalindrome = -1;

  for (int multiplicand = 999; multiplicand > 1; multiplicand--)
  {
    for (int multiplier = multiplicand; multiplier > 1; multiplier--)
    {
      int product = multiplier * multiplicand;
      if (largestPalindrome > -1 && product < largestPalindrome)
        break;

      if (isPalindrome(product))
      {
        largestPalindrome = product;
        break;
      }
    }
  }

  printf("result: %d\n", largestPalindrome);
}
