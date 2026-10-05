#include <stdio.h>
#include <math.h>

int main()
{
  double x = 1.5;
  printf("floor(%lf) = %lf\n", x, floor(x));
  printf("ceil(%lf) = %lf\n", x, ceil(x));
  printf("round(%lf) = %d\n", x, (int)round(x));

  printf("arccos(%lf) = %lf\n", x, acos(x));

  const double PI = 3.1415;
  double radius = 1.234;
  double volume = 4.0 / 3.0 * PI * pow(radius, 3);
  printf("The volume of the sphere is: %lf\n", volume);

  return 0;
}
