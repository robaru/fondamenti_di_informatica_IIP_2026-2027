#include <stdio.h>

#define SIZE 5

void addOne(int arr[SIZE])
{
    for (int i = 0; i < SIZE; ++i)
    {
        arr[i] = arr[i] + 1;
    }
}

void addOne_size(int arr[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = arr[i] + 1;
    }
}

void addOne_pointer(int *p_arr, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        (*(p_arr + i))++;
    }
}


int main()
{
    int a[SIZE] = {1, 2, 3, 4, 5};
    addOne(a);

    for (int i = 0; i < SIZE; ++i)
    {
        printf("%i\n", a[i]);
    }

    printf("Using size -----------\n");

    addOne_size(a, SIZE);

    for (int i = 0; i < SIZE; ++i)
    {
        printf("%i\n", a[i]);
    }

    printf("Using pointer -----------\n");

    addOne_pointer(a, SIZE);

    for (int i = 0; i < SIZE; ++i)
    {
        printf("%i\n", a[i]);
    }

    return 0;
}