#include <stdio.h>

#include "quick_sort.h"
#include "filling_array.h"

int main()
{
    int сontractorСounter = 0;
    
    int *array = filling_array();
    int size = array[0];
    
    quick_sort(array, 1, size - 1, &сontractorСounter);

    printf("The number of elements that have changed position: %d\n", сontractorСounter);
    
    return 0;
}
