#include <stdio.h>

int main()
{
  const double PI = 3.14159265359;

  double side = 1.234;       // m
  double radius = side / 2.; // m

  // Cube
  double cube_volume = side * side * side; // m^3
  double cube_area = 6 * side * side;      // m^2

  // Sphere
  double sphere_volume = 4. / 3. * PI * radius * radius * radius; // m^3
  double sphere_area = 4. * PI * radius * radius;                 // m^2

  // Ratios
  double ratio = sphere_volume / cube_volume;

  printf("Side:          %9.3f m\n", side);
  printf("\n");
  printf("Cube volume:   %9.3f m^3\n", cube_volume);
  printf("Sphere volume: %9.3f m^3\n", sphere_volume);
  printf("\n");
  printf("Cube area:     %9.3f m^2\n", cube_area);
  printf("Sphere area:   %9.3f m^2\n", sphere_area);
  printf("\n");
  printf("Ratio:         %9.3f\n", ratio);

  return 0;
}