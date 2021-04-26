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

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
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
char* muchBetterTimeConversion(char* s) {
  int hh, mm, ss ;
  char t12[3];
  sscanf(s, "%d:%d:%d%s", &hh, &mm, &ss, t12) ;

  if (strcmp(t12,"PM")==0 && hh!=12) hh += 12 ;
  if (strcmp(t12,"AM")==0 && hh==12) hh = 0 ;

  static char result[9];
  sprintf(result, "%02d:%02d:%02d", hh, mm, ss) ;
  return result;
}

char* timeConversion(char* s) {
  char* isInTheAm = strstr(s, "AM");
  char hourAsString[] = { s[0], s[1] };
  int hour = atoi(hourAsString);
  char* result = malloc(9 * sizeof(char));

  if (isInTheAm) {
    if (hour == 12) sprintf(result, "00%.*s", 6, s + 2);
    else sprintf(result, "%.*s", 8, s);
    return result;
  }

  if (hour == 12) sprintf(result, "%.*s", 8, s);
  else
  {
    hour += 12;
    sprintf(result, "%d%.*s", hour, 6, s + 2);
  }
  return result;
}

int main()
{
    char* s = readline();
    char* result = muchBetterTimeConversion(s);
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
