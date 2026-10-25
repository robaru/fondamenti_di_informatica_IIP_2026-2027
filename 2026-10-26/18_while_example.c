#include <stdio.h>
#include <stdbool.h>

int main()
{
  int age = -1;

  while (age < 0)
  {
    printf("Insert your age: ");
    scanf("%d", &age);
  }

  printf("Congratulations, you are %d years old\n", age);

  // while (true)
  // {
  //     printf("Hello\n");
  // }

  return 0;
}
