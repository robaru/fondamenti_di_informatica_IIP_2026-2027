#include <stdio.h>

#define SQUARE(x) ((x) * (x))
#define MAX_ITER 10000

int main()
{
  int a = -3;
  printf("(%d)^2 = %d\n", a, SQUARE(a));
  printf("(%d)^2 = %d\n", a + 1, SQUARE(a + 1));

  return 0;
}
