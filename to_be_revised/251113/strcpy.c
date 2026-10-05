#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

int main()
{
  char source[] = "I am a string :D";
  char destination[MAX_LEN];

  printf("Before strcpy: Source: '%s'\n", source);
  printf("Before strcpy: Destination: '%s'\n", destination);

  strcpy(destination, source); // Copy source into destination

  printf("After strcpy: Source: '%s'\n", source);
  printf("After strcpy: Destination: '%s'\n", destination);

  return 0;
}
