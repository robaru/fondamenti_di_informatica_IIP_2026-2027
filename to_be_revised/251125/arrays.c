#include <stdio.h>

int main()
{
  const unsigned size = 5;
  int arr[size] = {15, 25, 35, 45, 55};

  int idx = 0;
  printf("Element at index %d = %d\n", idx, arr[idx]);

  arr[4] = 100;

  for (int i = 0; i < size; i++)
  {
    printf("arr[%d] = %d\n", i, arr[i]);
  }

  return 0;
}
