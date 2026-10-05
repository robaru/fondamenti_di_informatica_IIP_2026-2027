#include <stdio.h>

int main()
{
  int mat[2][3] = {{10, 20, 30},
                   {40, 50, 60}};

  for (int row = 0; row < 2; row++)
  {
    for (int col = 0; col < 3; col++)
    {
      printf("row: %d, col: %d, mat[%d][%d] = %d\n", row, col, row, col, mat[row][col]);
    }
  }

  return 0;
}
