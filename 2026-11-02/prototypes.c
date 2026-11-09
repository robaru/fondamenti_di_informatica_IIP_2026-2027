#include <stdio.h>

// Function Prototypes
double calculateRectangleArea(double length, double width);

// Main
int main()
{
  double len, wid;
  printf("Insert rectangle length: ");
  scanf("%lf", &len);
  printf("Insert rectangle width: ");
  scanf("%lf", &wid);

  printf("The area is: %lf\n", calculateRectangleArea(len, wid));

  return 0;
}

// Function Definitions
double calculateRectangleArea(double length, double width)
{
  return length * width;
}
