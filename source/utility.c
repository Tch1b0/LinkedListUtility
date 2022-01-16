#include <stdlib.h>
#include <stdio.h>

#include <utility.h>

int *reverse_array(unsigned int array_length, int *array)
{
    int *new_array = malloc(sizeof(int) * array_length);

    int j = array_length - 1;
    for (int i = 0; i < array_length; i++)
    {
        new_array[j] = array[i];
        j--;
    }

    return new_array;
}

void print_array(unsigned int array_length, int *array)
{
    for (int i = 0; i < array_length; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
}