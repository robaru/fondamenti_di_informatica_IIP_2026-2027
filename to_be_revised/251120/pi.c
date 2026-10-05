#include <stdio.h>

int main()
{
  const double pi = 3.14159265359;

  printf("%-6.0f\t%6.0f\n", pi, pi);
  printf("%-6.1f\t%6.1f\n", pi, pi);
  printf("%-6.2f\t%6.2f\n", pi, pi);
  printf("%-6.3f\t%6.3f\n", pi, pi);
  printf("%-6.4f\t%6.4f\n", pi, pi);
  printf("\n");
  printf("%6.0f\t%-6.0f\n", pi, pi);
  printf("%6.1f\t%-6.1f\n", pi, pi);
  printf("%6.2f\t%-6.2f\n", pi, pi);
  printf("%6.3f\t%-6.3f\n", pi, pi);
  printf("%6.4f\t%-6.4f\n", pi, pi);
  printf("\n");

  return 0;
}