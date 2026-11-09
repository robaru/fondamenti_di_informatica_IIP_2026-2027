#include <stdio.h>
#include <string.h>

int main()
{
  // a string is an array of char that ends with '\0'
  char str1[] = "Hello";                           // size computed by the compiler
  char str2[20] = "Hello";                         // maximum size given by us
  char str3[] = {'H', 'e', 'l', 'l', 'o', '\0'};   // char by char: don't forget '\0'!

  printf("%s %s %s\n", str1, str2, str3);

  // single characters, like in any array
  printf("First char: %c\n", str1[0]);

  // strlen does not count the '\0'
  printf("Length of '%s': %zu\n", str1, strlen(str1));

  // the string ends at the first '\0', whatever comes after is ignored
  char name[] = "Mario\0 Rossi";
  printf("Length of '%s': %zu\n", name, strlen(name));

  return 0;
}
