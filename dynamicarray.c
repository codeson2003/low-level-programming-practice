#include <stdio.h>
#include <stdlib.h>

typedef struct DynamicArray
{
    int *data;
    int size;
    int capacity;
} DynamicArray;

void initArray(DynamicArray *arr, int capacity)
{

    arr->data = malloc(sizeof(int) * capacity);
    arr->size = 0;
    arr->capacity = capacity;
}

void append(DynamicArray *arr, int value)
{
    // Resize if we've hit capacity
    if (arr->size >= arr->capacity)
    {
        arr->capacity *= 2;
        arr->data = realloc(arr->data, sizeof(int) * arr->capacity);
        if (arr->data == NULL)
        {
            fprintf(stderr, "Memory allocation failed during append.\n");
            exit(1);
        }
    }

    // Add new value
    arr->data[arr->size] = value;
    arr->size++;
}

void removeAtIndex(DynamicArray *arr, int index)
{
    if (index < 0 || index >= arr->size)
    {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }

    for (int i = index; i < arr->size - 1; i++)
    {
        arr->data[i] = arr->data[i + 1];
    }

    arr->size--;
}

void freeArray(DynamicArray *arr)
{
    if (arr->data != NULL)
    {
        free(arr->data);
        arr->data = NULL;
    }

    arr->size = 0;
    arr->capacity = 0;
}

void printArray(DynamicArray *arr)
{
    printf("[");
    for (int i = 0; i < arr->size; i++)
    {
        printf("%d", arr->data[i]);
        if (i < arr->size - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

int main()
{

    DynamicArray *test;
    int size = 10;

    initArray(test, size);

    append(test, 5);
    append(test, 15);
    append(test, 25);
    append(test, 35);

    printArray(test);

    removeAtIndex(test, 2);

    printArray(test);

    freeArray(test);

    return 0;
}