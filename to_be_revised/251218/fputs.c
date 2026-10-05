#include <stdio.h>

int main()
{
  FILE *fptr = fopen("example_fputs.txt", "w");

  if (fptr == NULL)
  {
    printf("Error creating/opening file\n");
    return 1;
  }

  fputs("Good news everyone!\n", fptr);
  fputs(" - Prof. Hubert J. Farnsworth\n", fptr);

  fclose(fptr);

  return 0;
}
