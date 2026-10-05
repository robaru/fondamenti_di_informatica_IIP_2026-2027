#include <stdio.h>
#include <stdbool.h>

#define DEBUG

void swap(int *x, int *y);
void printArray(const int arr[], size_t size);
void bubble_sort(int arr[], size_t size);

int main()
{
  const unsigned size = 5;
  // int arr[size] = {64, 25, 12, 22, 11};
  int arr[size] = {11, 12, 22, 25, 64};

  printf("Array before bubble sort: ");
  printArray(arr, size);

  bubble_sort(arr, size);

  printf("Array after bubble sort:  ");
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

void bubble_sort(int arr[], size_t size)
{
  for (int step = 0; step < size - 1; step++)
  {
    // Step x
    bool swapped = false;

    for (int i = 0; i < size - 1 - step; i++)
    {
      if (arr[i] > arr[i + 1])
      {
        swap(&arr[i], &arr[i + 1]);
        swapped = true;
      }
    }

#ifdef DEBUG
    printf("Debug @ step %d\n", step);
    printArray(arr, size);
#endif

    // Optimization
    if (!swapped)
    {
#ifdef DEBUG
      printf("Skipping remaining steps.\n");
#endif
      return;
    }
  }
}
