#include <stdio.h>
#include <string.h>

int main()
{
  char text[30] = "Ciao";

  printf("initialisation: %s\n", text);
  // copy
  strcpy(text, "This is an");
  printf("strcpy:  '%s'\n", text);

  // concatenate
  strcat(text, " example");
  printf("strcat:  '%s'\n", text);

  // the "n" versions work on at most n characters
  char start[30] = "";
  strncpy(start, text, 2);
  printf("strncpy: '%s'\n", start);

  // compare: 0 if equal, < 0 or > 0 otherwise (alphabetical order)
  printf("strcmp(\"Mario\", \"Mario\") = %d\n", strcmp("Mario", "Mario"));
  printf("strcmp(\"Mario\", \"mario\") = %d\n", strcmp("Mario", "mario")); // case matters!

  // N.B. text == "This is an example" does NOT compare the content: use strcmp
  if (strcmp(text, "This is an example") == 0)
  {
    printf("Same text!\n");
  }

  return 0;
}
