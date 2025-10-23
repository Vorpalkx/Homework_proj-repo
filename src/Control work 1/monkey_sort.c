#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main()
{
  int array[7] = {2, 5, 8, 3, 12, 7, 9};
  srand(time(NULL));
  int tmp = 0;
  int k = 0;
  int l = 0;
  A:
  k = rand() % 6;
  l = rand() % 6;
  tmp = array[k];
  array[k] = array[l];
  array[l] = array[k];
  for (int i = 1; i < 7; i++) {
      if (array[i-1] > array[k])
          goto A;
  }
  for (int i = 0; i < 7; i++) {
      printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}
