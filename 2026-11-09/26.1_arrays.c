#include <stdio.h>

int main()
{
  // initialization together with the declaration
  int arr[5] = {15, 25, 35, 45, 55};

  // access an element (indices go from 0 to 4)
  printf("> arr[4] = %d\n", arr[4]);

  // modify an element
  arr[4] = 100;
  printf(">> arr[4] = %d\n", arr[4]);

  // print all elements with a for loop
  for (int i = 0; i < 5; i++)
  {
    printf("arr[%d] = %d\n", i, arr[i]);
  }

  // initialization after the declaration, with a for loop
  int squares[5];

  for (int i = 0; i < 5; i++)
  {
    squares[i] = i * i;
  }

  // alternative solution
  printf("Dim squares %lu in bytes\n", sizeof(squares));
  printf("Dim int %lu in bytes\n", sizeof(int));

  int num_elements = sizeof(squares)/sizeof(int);
  printf("Number of elements in squares %lu\n", num_elements);

  for (int i = 0; i < num_elements; i++)
  {
    squares[i] = i * i;
  }
  printf("squares[3] = %d\n", squares[3]);

  return 0;
}
