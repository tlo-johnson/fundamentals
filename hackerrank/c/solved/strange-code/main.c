#include <string.h>
#include <stdio.h>

long long strangeCounter(long long time) {
  long long value = 3;
  long long count = 1;

  while (count < time) {
    count += value;
    value *= 2;
  }

  return count == time ? value : count - time;
}

int main() {
  long long time;
  scanf("%lld", &time);
  printf("%lld", strangeCounter(time));
}
