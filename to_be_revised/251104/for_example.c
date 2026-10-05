#include <stdio.h>

int main()
{
  double res = 1.1;
  for (int i = 0; i < 10; i++)
  {
    res *= res;
    printf("Res: %lf\n", res);
  }

  // for (int i = 0; i != 5; i += 2)
  // {
  //     printf("Hello!\n");
  // }

  // initialization: do nothing
  // condition:
  // update: do nothing
  // pro tip: ctrl+c to terminate
  // for (;;)
  // {
  //     printf("Hello!\n");
  // }

  return 0;
}
