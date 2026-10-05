#include <stdio.h>

int square_sum(int a, int b)
{
  int result = a * a + b * b;
  return result;
}

int main()
{
  int v1 = 1;
  int v2 = 3;
  int v3 = 5;

  int tot = square_sum(v1, v2);
  printf("Square sum of %d and %d = %d\n", v1, v2, tot);

  tot = square_sum(v2, v3);
  printf("Square sum of %d and %d = %d\n", v2, v3, tot);

  return 0;
}
