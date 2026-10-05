#include <stdio.h>
#include <string.h>

int main()
{
  char name[] = "Mattia";
  char surname[] = "Guidolin";

  int res1 = strcmp(name, surname);
  int res2 = strcmp(name, "Mattia");
  int res3 = strcmp("guidolin", surname);

  printf("Comparison between '%s' and '%s': %d\n", name, surname, res1);
  printf("Comparison between '%s' and 'Mattia': %d\n", name, res2);
  printf("Comparison between 'guidolin' and '%s': %d\n", surname, res3);

  if (strcmp(name, "Mattia") == 0)
  {
    printf("Hi!\n");
  }
  else
  {
    printf("Goodbye\n");
  }

  return 0;
}
