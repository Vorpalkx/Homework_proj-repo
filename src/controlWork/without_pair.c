#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main()
{
    int counter = 0;
    int numbers[MAX_SIZE];
    int input;

    while (counter < MAX_SIZE) {
        scanf("%d", &input);
        if (input == 0) {
            break;
        }
        numbers[counter] = input;
        counter++;
    }

    for (int i = 0; i < counter; i++) {
        int cnt = 0;
        for (int j = 0; j < counter; j++) {
            if (numbers[i] == numbers[j] - 1) {
                cnt++;
            }
        }
        if (cnt == 0) {
            printf("%d ", numbers[i]);
        }
    }
    printf("\n");

    return 0;
}
