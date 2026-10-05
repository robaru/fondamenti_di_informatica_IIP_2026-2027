#include <stdio.h>

void swap_bugged(int x, int y);
void swap(int *x, int *y);

int main()
{
  int a = 10, b = 20;
  swap(&a, &b);
  printf("After swap(): a = %d, b = %d\n", a, b);

  return 0;
}

void swap_bugged(int x, int y)
{
  int tmp = x;
  x = y;
  y = tmp;
}

void swap(int *x, int *y)
{
  int tmp = *x;
  *x = *y;
  *y = tmp;
}
