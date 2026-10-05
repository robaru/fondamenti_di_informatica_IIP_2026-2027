#include <stdio.h>

#define MAX 50

int main()
{
  char str[MAX];

  printf("What's your name? ");
  fgets(str, MAX, stdin);

  printf("\nHello, %s!\n", str);

  return 0;
}
