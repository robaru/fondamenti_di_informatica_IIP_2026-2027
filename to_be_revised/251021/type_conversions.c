#include <stdio.h>

int main()
{
  const double PI = 3.14159;
  double radius = 1.234;

  double sphere_volume = 4 / 3.0 * PI * radius * radius * radius;
  printf("The volume of a sphere with radius %lf is: %lf\n", radius, sphere_volume);

  double sum = (int)sphere_volume + 1;
  printf("The sum is: %lf\n", sum);

  return 0;
}
