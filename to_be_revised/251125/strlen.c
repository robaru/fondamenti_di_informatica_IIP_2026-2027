#include <stdio.h>
#include <string.h>

int main()
{
  char name[] = "Mattia\0 Guidolin";
  printf("Length of '%s': %lu\n", name, strlen(name));

  return 0;
}
