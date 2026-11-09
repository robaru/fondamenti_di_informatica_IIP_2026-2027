#include <stdio.h>

int somma(int a, int b)
{
  printf("interno somma = %d\n", a);
  return a + b;
}

int main()
{
  int x = 10, y = 20;

  if (x > 1)
  {
    printf("x = %d, y = %d\n", x, y);

    if (y > 1)
    {
      x++;
      y++;
      int z = 30;

      printf("x = %d, y = %d, z = %d\n", x, y, z);
    }

    // here z does not exist
    //printf("z = %d\n", z);
  }
  printf("somma = %d\n", somma(x,y));
  printf("x = %d\n", x);
  printf("y = %d\n", y);

  // here z does not exist
  // printf("z = %d\n", z);

  return 0;
}
