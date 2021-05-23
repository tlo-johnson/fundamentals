#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
char* hoursInWords(int h) {
  switch (h) {
    case 1:
      return "one";
    case 2:
      return "two";
    case 3:
      return "three";
    case 4:
      return "four";
    case 5:
      return "five";
    case 6:
      return "six";
    case 7:
      return "seven";
    case 8:
      return "eight";
    case 9:
      return "nine";
    case 10:
      return "ten";
    case 11:
      return "eleven";
    case 12:
      return "twelwe";
  }

  return "invalid time"
}

char* minutesInWords(int m) {
  if (m > 30)
    m = 30 - (m - 30);

  switch (m) {
    case 1:
      return "one minute";
    case 2:
      return "two minutes";
    case 3:
      return "three minutes";
    case 4:
      return "four minutes";
    case 5:
      return "five minutes";
    case 6:
      return "six minutes";
    case 7:
      return "seven minutes";
    case 8:
      return "eight minutes";
    case 9:
      return "nine minutes";
    case 10:
      return "ten minutes";
    case 11:
      return "eleven minutes";
    case 12:
      return "twelwe minutes";
    case 13:
      return "thirteen minutes";
    case 14:
      return "fourteen minutes";
    case 15:
      return "quarter";
    case 16:
      return "sixteen minutes";
    case 17:
      return "seventeen minutes";
    case 18:
      return "eighteen minutes";
    case 19:
      return "nineteen minutes";
    case 20:
      return "twenty minutes";
    case 21:
      return "twenty one minutes";
    case 22:
      return "twenty two minutes";
    case 23:
      return "twenty three minutes";
    case 24:
      return "twenty four minutes";
    case 25:
      return "twenty five minutes";
    case 26:
      return "twenty six minutes";
    case 27:
      return "twenty seven minutes";
    case 28:
      return "twenty eight minutes";
    case 29:
      return "twenty nine minutes";
    case 30:
      return "half";
  }

  return "invalid time"
}

char* timeInWords(int h, int m) {
  char* result = malloc(100 * sizeof(char));

  if (m == 0) {
    sprintf(result, "%s o' clock", hoursInWords(h));
    return result;
  }

  if (m <= 30) {
    sprintf(result, "%s past %s", minutesInWords(m), hoursInWords(h));
    return result;
  }

  sprintf(result, "%s to %s", minutesInWords(m), hoursInWords(h + 1));
  return result;
}

int main()
{
    int h = parse_int(ltrim(rtrim(readline())));

    int m = parse_int(ltrim(rtrim(readline())));

    char* result = timeInWords(h, m);

    printf("%s\n", result);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
