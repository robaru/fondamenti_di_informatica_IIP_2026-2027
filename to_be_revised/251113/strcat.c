#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

int main()
{
  char destination[MAX_LEN] = "This is an";
  char source[MAX_LEN] = " example";

  printf("Before strcat: Destination: '%s'\n", destination);

  strcat(destination, source);

  printf("After strcat: Destination: '%s'\n", destination);

  return 0;
}
