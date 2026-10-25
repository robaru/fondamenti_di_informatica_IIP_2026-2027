#include <stdio.h>
#include <stdbool.h>

int main()
{
  int age = 0;

  do
  {
    printf("Insert your age: ");
    scanf("%d", &age);
  } while (age < 0 || age > 100);

  printf("Congratulations, you are %d years old\n", age);

  // int i = 4;
  // do
  // {
  //     printf("Hello!\n");
  //     i++;
  // }
  // while (i < 3);

  return 0;
}
