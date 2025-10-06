#include <stdio.h>
#include <stdlib.h>

#include "filling_array.h"

int *filling_array()
{
    int numbers[100];
    int counter = 1;
    while ((counter < 100) && scanf("%d", &numbers[counter]) == 1) {
        counter += 1;
        if (getchar() == '\n')
            break;
    }
    
    numbers[0] = counter;
    
    int *array = (int*)malloc(counter * sizeof(int));
    for (int i = 0; i < counter; i++)
        array[i] = numbers[i];
    return array;
}
