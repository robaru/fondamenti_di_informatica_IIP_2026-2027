#include <stdio.h>

int main()
{
  int test[3] = {1,2,3};
  int mat[2][3] = {{10, 20, 30},
                  {40, 50, 60}};

  // access a single element: mat[row][col]
  printf("mat[1][2] = %d\n\n", mat[1][2]);

  // print the whole matrix: one loop for the rows, one for the columns
  for (int row = 0; row < 2; row++)
  {
    for (int col = 0; col < 3; col++)
    {
      printf("%d ", mat[row][col]);
    }
    printf("\n");
  }

  return 0;
}
