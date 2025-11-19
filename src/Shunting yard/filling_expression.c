#include <stdio.h>
#include <stdlib.h>

char* filling_expression()
{
    printf("Enter a filling_expression of no more than 100 characters:\n");

    char string[100];
    int counter = 0;
    char c;

    // Entering a expression from the keyboard
    while (counter < 99 && (c = getchar()) != '\n' && c != EOF) {
        if (c != ' ') {
            string[counter++] = c;
        }
    }

    // Allocating dynamic memory for less memory usage
    char* array = (char*)malloc(counter * sizeof(char));
    for (int i = 0; i < counter; i++)
        array[i] = string[i];

    return array;
}
