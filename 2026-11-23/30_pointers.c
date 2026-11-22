#include <stdio.h>

struct Point
{
  float x;
  float y;
};

int main()
{
  // Primitive data types
  float x = 42.0;
  float *pointer_to_x = &x;

  printf("Value of pointer_to_x: %p\n", pointer_to_x);
  printf("Value pointed: %f\n", *pointer_to_x);

  *pointer_to_x += 10;

  printf("Value of x: %f\n", x);
  printf("---\n");

  // Arrays
  int arr[] = {10, 1, 2, 3};
  int *ptr2arr = arr;

  printf("Value of ptr2arr: %p\n", ptr2arr);
  printf("Value pointed: %d\n", *ptr2arr);
  printf("---\n");

  // Structs
  struct Point origin = {.x = 0.1, .y = 0.2};
  struct Point *ptr2o = &origin;

  printf("Value of ptr2o: %p\n", ptr2o);
  printf("Value pointed (x): %f\n", ptr2o->x);
  printf("Value pointed (y): %f\n", ptr2o->y);
  printf("---\n");

  // Double pointers
  float *ptr2x = &x;
  float **ptr2ptr2x = &ptr2x;

  printf("Value of ptr2x: %p\n", ptr2x);
  printf("Value pointed by ptr2x: %f\n", *ptr2x);
  printf("Value of ptr2ptr2x: %p\n", ptr2ptr2x);
  printf("Value pointed by ptr2ptr2x: %p\n", *ptr2ptr2x);
  printf("Value of x: %f\n", **ptr2ptr2x);
  printf("---\n");

  // NULL pointers
  int *ptr2null = NULL;

  printf("Value of ptr2null: %p\n", ptr2null);
  // printf("Value pointed by ptr2null: %d\n", *ptr2null); // Segmentation fault (core dumped)
  printf("---\n");

  // Void pointers
  int m = -36;
  void *ptr2m;
  ptr2m = &m;

  printf("Value of ptr2m: %p\n", ptr2m);
  printf("Value pointed by ptr2m: %d\n", *(int *)ptr2m);
  // printf("Value pointed by ptr2m: %u\n", *(unsigned int*)ptr2m); // NO!!!

  return 0;
}
