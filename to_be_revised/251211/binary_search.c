#include <stdio.h>

#define DEBUG

void swap(int *x, int *y);
void printArray(const int arr[], size_t size);
int *partition(int *low, int *high);
void quicksort_ptr(int *low, int *high);
void quicksort(int arr[], size_t size);

int binary_search(int arr[], size_t size, int searched_val);

int main()
{
  const unsigned size = 10;
  int arr[size] = {64, 25, 12, 22, 18, 1, 4, 35, 21, 30};

  printf("Array before quicksort: ");
  printArray(arr, size);

  quicksort(arr, size);

  printf("Array after quicksort:  ");
  printArray(arr, size);

  printf("Searching for value 1\n");
  int val = 21;
  int idx = binary_search(arr, size, val);
  printf("%d is in position %d\n", val, idx);

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

int binary_search(int arr[], size_t size, int searched_val)
{
  int low_idx = 0, high_idx = size - 1;
  int iteration = 0;

  while (low_idx <= high_idx)
  {
    int mid_idx = low_idx + (high_idx - low_idx) / 2;

#ifdef DEBUG
    printf("Iteration %d\n", ++iteration);
    printf("Mid: %d, low: %d, high: %d\n", mid_idx, low_idx, high_idx);
    printf("Looking at arr[%d] = %d\n", mid_idx, arr[mid_idx]);
    printf("Looking for %d\n", searched_val);
#endif

    if (arr[mid_idx] == searched_val)
    {
      return mid_idx;
    }

    if (arr[mid_idx] > searched_val)
    {
      high_idx = mid_idx - 1;
    }
    else
    {
      low_idx = mid_idx + 1;
    }
  }

  // We did not find searched_val inside arr[]
  return -1;
}
