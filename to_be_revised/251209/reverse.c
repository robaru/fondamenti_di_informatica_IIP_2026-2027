#include <stdio.h>

void swap(int *x, int *y);
void printArray(const int arr[], size_t size);
void reverse(int arr[], size_t size);

int main()
{
  const unsigned size = 7;
  int steps[size] = {1, 2, 3, 4, 5, 10, 100};

  printf("Array before reverse: ");
  printArray(steps, size);

  reverse(steps, size);

  printf("Array after reverse:  ");
  printArray(steps, size);

  return 0;
}

void swap(int *x, int *y)
{
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

void reverse(int arr[], size_t size)
{
  for (int i = 0; i < size / 2; i++)
  {
    swap(&arr[i], &arr[size - i - 1]);
  }
}

void printArray(const int arr[], size_t size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
