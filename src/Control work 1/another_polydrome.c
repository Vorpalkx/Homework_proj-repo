#include <stdio.h>
#include <stdlib.h>

int main()
{
    int massive[100];
    int count = 0;
    while ((count < 100) && scanf("%d", &massive[count]) == 1) {
        count++;
        if (getchar() == '\n')
            break;
    }
    printf("Полиндромы по двоичной системе: ");
    for (int i = 0; i < count; i++) {
        int item = massive[i];
        int bin[20] = {0};
        int k = 0;
        while (item != 0) {
            bin[k] = item % 2;
            item /= 2;
            k++;
        }
        int flag = 1;
        for (int j = 0; j < ((k / 2) + 1); j++) {
            if (bin[j] != bin[k-1-j]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            printf("%d ", massive[i]);
    }
    printf("\n");
    return 0;
}
