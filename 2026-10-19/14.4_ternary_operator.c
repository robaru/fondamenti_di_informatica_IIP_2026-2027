#include <stdio.h>

int main()
{
  int first, second;

  printf("Insert the first number: ");
  scanf("%d", &first);
  printf("Insert the second number: ");
  scanf("%d", &second);

  // if (first > second)
  // {
  //     printf("%d is greater than %d\n", first, second);
  // }
  // else
  // {
  //     printf("%d is greater or equal than %d\n", second, first);
  // }
  (first > second) ? printf("%d is greater than %d\n", first, second) : printf("%d is greater or equal than %d\n", second, first);

  int res = (first > second) ? first + second : first - second;
  printf("The result is: %d\n", res);

  printf("Goodbye\n");

  return 0;
}
