#include <stdio.h>

int main()
{
  FILE *fptr = fopen("example_fputc.txt", "w");

  if (fptr == NULL)
  {
    printf("Error creating/opening file\n");
    return 1;
  }

  fputc('M', fptr);
  fputc('G', fptr);
  fputc('\n', fptr);

  fclose(fptr);

  return 0;
}
