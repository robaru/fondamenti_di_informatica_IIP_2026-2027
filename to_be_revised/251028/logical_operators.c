#include <stdio.h>
#include <stdbool.h>

int main()
{
  bool a = false;
  bool b = false;
  bool c = true;

  bool result = (a || b) || !c;
  printf("The result is: %d\n", result);
}
