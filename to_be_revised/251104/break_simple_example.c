#include <stdio.h>

int main()
{
  int max = 1000;
  for (int n = max; n >= 0; n--)
  {
    if ((n % 3 == 0) && (n % 4 == 0) && (n % 7 == 0))
    {
      printf("The greatest number < %d divisible by 3, 4, and 7 is: %d\n", max, n);
      break;
    }
  }

  return 0;
}
