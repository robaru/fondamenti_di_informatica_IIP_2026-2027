#include <stdio.h>

// #define DEBUG

void swap(int *x, int *y);
void printArray(const int arr[], size_t size);
int *partition(int *low, int *high);
void quicksort_ptr(int *low, int *high);
void quicksort(int arr[], size_t size);

int main()
{
  const unsigned size = 10;
  int arr[size] = {64, 25, 12, 22, 18, 1, 4, 35, 21, 30};

  printf("Array before quicksort: ");
  printArray(arr, size);

  quicksort(arr, size);

  printf("Array after quicksort:  ");
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

int *partition(int *low, int *high)
{
  // step 1
  int *pivot_ptr = high;
  int *i = low - 1;

  // steps 2 to 5
  for (int *j = low; j < high; j++)
  {
    if (*j < *pivot_ptr)
    {
      swap(++i, j);
    }
  }

  // step 6
  swap(i + 1, pivot_ptr);
  return i + 1;
}

void quicksort_ptr(int *low, int *high)
{
  if (low < high)
  {
    int *pivot_ptr = partition(low, high);

#ifdef DEBUG
    printf("Pivot: %d\n", *pivot_ptr);
    printArray(low, high - low);
    printf("Low: %p, High: %p\n", low, high);
#endif
    // Now we have:
    // - pivot_ptr pointing toi the correct position of the pivot
    // - low to pivot_ptr - 1: contains all the elements < pivot
    // - pivot_ptr + 1 to high: contains all the elements >= pivot
    quicksort_ptr(low, pivot_ptr - 1);
    quicksort_ptr(pivot_ptr + 1, high);
  }
}

void quicksort(int arr[], size_t size)
{
  if (size <= 1)
  {
    return;
  }

  quicksort_ptr(arr, arr + size - 1);
}
