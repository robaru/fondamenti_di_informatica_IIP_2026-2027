#include <stdio.h>

int main()
{
  int var;
  printf("Insert a value from 1 to 7: ");
  scanf("%d", &var);

  switch (var)
  {
  case 1:
    printf("Case 1 is matched\n");
    break;
  case 2:
    printf("Case 2 is matched\n");
    break;
  case 3:
    printf("Case 3 is matched\n");
    break;
  case 4: // equivalent to: if (var == 4)
    printf("Case 4 is matched\n");
    break;
  case 5:
  case 6:
  case 7:
    printf("Case 5 to 7 is matched\n");
    break;
  default:
    printf("I said from 1 to 7!!!!\n");
  }

  return 0;
}
