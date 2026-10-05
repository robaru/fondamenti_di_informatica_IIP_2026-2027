#include <stdio.h>

/********
 * main *
 ********/
int main()
{
    // This is a single-line comment
    printf("1st\n"); // This is also a comment
    // printf("2nd\n");
    printf("3rd\n");

    int a = 1, b = 2, c = 3;
    int res = a + /* b + */ c; // DON'T DO IT!
    printf("The result is: %d\n", res);

    return 0;
}
