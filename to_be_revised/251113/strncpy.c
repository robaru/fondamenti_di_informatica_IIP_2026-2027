#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

int main()
{
  char source[] = "I am a string :D";
  char destination[MAX_LEN];

  printf("Before strncpy: Source: '%s'\n", source);
  printf("Before strncpy: Destination: '%s'\n", destination);

  strncpy(destination, source, 13); // Copy source into destination

  printf("After strncpy: Source: '%s'\n", source);
  printf("After strncpy: Destination: '%s'\n", destination);

  return 0;
}
