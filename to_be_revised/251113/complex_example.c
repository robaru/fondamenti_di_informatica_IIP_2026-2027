#include <stdio.h>
#include <complex.h>

int main()
{
  double real = 1.3;
  double imag = 4.9;

  double complex z = real + imag * I; // z = 1.3 + 4.9j
  double complex z_conj = conj(z);

  printf("z* = %.1lf + %.1lfj\n", creal(z_conj), cimag(z_conj));

  return 0;
}
