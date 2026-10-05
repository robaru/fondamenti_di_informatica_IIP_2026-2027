#include <stdio.h>

// #define DEBUG
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void printArray(const int *arr, size_t size);
void addOne(int arr[], size_t size);
float avg(const int arr[], size_t size);
int max(const int arr[], size_t size);

int main()
{
  const unsigned size = 5;
  int a[size] = {31, 45, 2, 67, 89};

  printf("Original array:\n");
  printArray(a, size);

  addOne(a, size);

  printf("Array after addOne():\n");
  printArray(a, size);

  printf("Average value of the array: %f\n", avg(a, size));

  // addOne(a, size);
  // printf("Average after addOne(): %f\n", avg(a, size));

  int max_val = max(a, size);
  printf("The maximum value of the array is: %d\n", max_val);

  return 0;
}

void printArray(const int *arr, size_t size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void addOne(int arr[], size_t size)
{
  for (int i = 0; i < size; i++)
  {
    arr[i]++;
  }
}

float avg(const int arr[], size_t size)
{
  if (size <= 0)
  {
    return 0.; // Would be better to return NaN
  }

  float sum = 0.;
  for (int i = 0; i < size; i++)
  {
    sum += arr[i];
  }
  return (sum / size);
}

int max(const int arr[], size_t size)
{
  if (size <= 0)
  {
    return 0.; // Would be better to return NaN
  }

  int max = arr[0];
  for (int i = 1; i < size; i++)
  {
    max = MAX(max, arr[i]);
#ifdef DEBUG
    printf("### max @ iteration %d = %d\n", i, max);
#endif
  }
  return max;
}
