#include <stdio.h>

#define DEBUG

int main()
{
  printf("This is my program! :D\n");

#ifdef DEBUG
  printf("This is for debugging purposes\n");
#endif

  printf("This is my program again! :D\n");

  return 0;
}
