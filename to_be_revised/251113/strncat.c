#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

int main()
{
  char destination[MAX_LEN] = "This is an";
  char source[MAX_LEN] = " example";

  printf("Before strncat: Destination: '%s'\n", destination);

  strncat(destination, source, 5);

  printf("After strncat: Destination: '%s'\n", destination);

  return 0;
}
