#include <stdio.h>

#define LOG_LEVEL 1

int main()
{
#if LOG_LEVEL == 0
  printf("This is VERY important\n");
#elif LOG_LEVEL == 1
  printf("This is  important\n");
#elif LOG_LEVEL == 2
  printf("This is not very important\n");
#else
  printf("This is NOT important\n");
#endif

  return 0;
}
