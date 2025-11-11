#include <stdio.h>
#include <stdlib.h>

#include "quick_sort.h"
#include "filling_array.h"

int main()
{
    int сontractorСounter = 0;
    
    int size = 0;
    int *array = filling_array(&size); 
    quick_sort(array, 0, size - 1, &сontractorСounter);
    free(array);
    
    printf("The number of elements that have changed position: %d\n", сontractorСounter);
    
    return 0;
}
