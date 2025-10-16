#include <stdlib.h>
#include <stdio.h>

int *string_filling()
{
    char string[100];
    int counter = 1;
    while ((counter < 100) && scanf("%c", &string[counter]) == 1) {
    	    if (string[counter] == '\n')
	        break;
	    counter++;

    }
    string[0] = counter;
    int *array = (int*)malloc(counter*sizeof(int));
    for (int i = 0; i < counter; i++)
        array[i] = string[i];
    return array;
}
