#include "quick_sort.h"

void quick_sort(int *array, int low, int high, int *counter)
{
    int opElem = array[high];
    int i = low - 1;
    if (low >= high)
        return;
    for (int j = low; j < high; j++) {
        if (array[j] < opElem) {
            i++;
            int tmp = array[j];
            array[j] = array[i];
            array[i] = tmp;
            *counter += 2;
        }
    }
    array[high] = array[i + 1];
    array[i + 1] = opElem;
    *counter += 2;
    
    quick_sort(array, low, i, counter);
    quick_sort(array, i + 2, high, counter);
}
