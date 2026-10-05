#include <stdio.h>

int main()
{
  FILE *fptr = fopen("example_fprintf.txt", "w");

  if (fptr == NULL)
  {
    printf("Error creating/opening file\n");
    return 1;
  }

  int n = 42;
  float f = 12.345;
  char name[] = "Mattia";

  fprintf(fptr, "Name: %s\n", name);
  fprintf(fptr, "Lucky number: %d\n", n);
  fprintf(fptr, "Formatted float: %.2f\n", f);

  fclose(fptr);

  return 0;
}
