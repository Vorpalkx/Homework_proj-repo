#include <stdio.h>

int main()
{
    int massive[100];
    int count = 0;
    while ((count < 100) && scanf("%d", &massive[count]) == 1) {
        count++;
        if (getchar() == '\n')
            break;
    }
    int answers[100] = {0};
    int largest = 0;
    int cnt = 0;
    for (int i = 0; i < count; i++) {
        int item = massive[i];
        int sum = 0;
        while (item != 0) {
            sum += item % 10;
            item /= 10;
        }
        if (largest < sum) {
            largest = sum;
            cnt = 0;
            answers[cnt] = massive[i];
            cnt++;
        } else if (largest == sum) {
            answers[cnt] = massive[i];
            cnt++;
        } else {
            continue;
        }
    }
    printf("Числа с наибольшей суммой цифр: ");
    for (int i = 0; i < cnt; i++) {
        printf("%d ", answers[i]);
    }
    printf("\nНаибольшая сумма цифр: %d\n", largest);
    return 0;
}
