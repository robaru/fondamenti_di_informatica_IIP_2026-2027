#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], unsigned int size);

int main()
{
  unsigned int size;

  printf("enter the number of elements: ");
  scanf("%u", &size);

  printf("Allocating %u elements\n", size);
  int *array = (int *)calloc(size, sizeof(int));

  if (array == NULL)
  {
    printf("Call to calloc() failed\n");
    return 1;
  }

  for (int i = 0; i < size; i++)
  {
    array[i] = 2 * i + 1;
  }

  printf("Array location before realloc: %p\n", array);
  printf("The array contains the elements: ");
  printArray(array, size);

  // Realloc
  unsigned int elements_to_add;
  printf("enter the number of elements to add: ");
  scanf("%u", &elements_to_add);
  size += elements_to_add;

  array = (int *)realloc(array, size * sizeof(int));

  if (array == NULL)
  {
    printf("Call to realloc failed\n");
    return 2;
  }

  for (int i = size - elements_to_add; i < size; i++)
  {
    array[i] = 2 * i;
  }

  printf("Array location after realloc: %p\n", array);
  printf("The array contains the elements: ");
  printArray(array, size);

  free(array);

  return 0;
}

void printArray(int arr[], unsigned int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
