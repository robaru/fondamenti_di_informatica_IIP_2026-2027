#include <stdio.h>

int main()
{
  const unsigned size = 3;
  int arr[size] = {10, 100, 1000};

  int *ptr1 = arr;

  // Increment / decrement
  for (int i = 0; i < size; i++)
  {
    printf("Value of *ptr1: %d\n", *ptr1);
    printf("Value of ptr1: %p\n", ptr1);
    ptr1++;
  }

  ptr1 -= 2;
  printf("Value of *ptr1: %d\n", *ptr1);

  // Pointer subtraction
  int *ptr2 = &arr[size - 1];
  int diff = ptr1 - ptr2;
  printf("Diff: %d\n", diff);

  // Pointer comparison
  if (ptr1 < ptr2)
  {
    printf("ptr1 points to an element before the one pointed by ptr2.\n");
  }
  else if (ptr1 > ptr2)
  {
    printf("ptr1 points to an element after the one pointed by ptr2.\n");
  }
  else
  {
    printf("ptr1 and ptr2 are pointing to the same element.\n");
  }

  // Pointer assignment
  int *ptr3 = ptr2;

  printf("Value of ptr2: %p\n", ptr2);
  printf("Value of ptr3: %p\n", ptr3);

  return 0;
}
