#include <stdio.h>
#include <stdlib.h>

int* string_filling()
{
    printf("Enter a string of no more than 100 characters:\n");
    char string[100];
    int counter = 1;
    // Entering a string from the keyboard
    while ((counter < 100) && scanf("%c", &string[counter]) == 1) {
        if (string[counter] == '\n')
            break;
        counter++;
    }

    string[0] = counter;
    // Allocating dynamic memory for less memory usage
    int* array = (int*)malloc(counter * sizeof(int));
    for (int i = 0; i < counter; i++)
        array[i] = string[i];

    return array;
}
