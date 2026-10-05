#include <stdio.h>

void change_sign(int *n);

int main()
{
  int a = 10;
  change_sign(&a);

  printf("Value of a: %d\n", a);

  return 0;
}

void change_sign(int *n)
{
  *n = -*n;
}
