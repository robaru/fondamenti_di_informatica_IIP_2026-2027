#include <stdio.h>

int main()
{
  for (int i = 0; i < 2; i++)
  {
    printf("outer loop\n");

    for (int j = 0; j < 3; j++)
    {
      printf("    inner loop: i = %d, j = %d\n", i, j);
    }
  }

  return 0;
}
