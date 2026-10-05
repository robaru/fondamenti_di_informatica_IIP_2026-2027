#include <stdio.h>

int square_sum(int a, int b)
{
  return a * a + b * b;
}

int main()
{
  int v1 = 1;
  int v2 = 3;
  int v3 = 5;

  // printf("Square sum of %d and %d = %d\n", v1, v2, square_sum(v1, v2));
  printf("Tot = %d\n", square_sum(v3, square_sum(v1, v2)));

  return 0;
}
