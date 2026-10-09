#include <stdio.h>

int main()
{
    float n = 12345.67890;

    printf("n: %f\n", n);
    printf("n: %-f\n", n);
    printf("n: %20f\n", n);
    printf("n: %-20f\n", n);
    printf("n: %20.2f\n", n);
    printf("n: %20.20f\n", n);

    return 0;
}
