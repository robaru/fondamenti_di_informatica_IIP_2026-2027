#include <stdio.h>

#define DEBUG

void swap(int *x, int *y);
void printArray(const int arr[], size_t size);
void selection_sort(int arr[], size_t size);

int main()
{
  const unsigned size = 5;
  int arr[size] = {64, 25, 12, 22, 11};

  printf("Array before selection sort: ");
  printArray(arr, size);

  selection_sort(arr, size);

  printf("Array after selection sort:  ");
  printArray(arr, size);

  return 0;
}

void swap(int *x, int *y)
{
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

void printArray(const int arr[], size_t size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void selection_sort(int arr[], size_t size)
{
  for (int step = 0; step < size - 1; step++)
  {
    int min_idx = step;

    // Find the index of the min val between idx = step and idx = size - 1
    for (int i = step + 1; i < size; i++)
    {
      if (arr[i] < arr[min_idx])
      {
        min_idx = i;
      }
    }

    swap(&arr[step], &arr[min_idx]);

#ifdef DEBUG
    printf("Debug @ step %d\n", step);
    printArray(arr, size);
#endif
  }
}
