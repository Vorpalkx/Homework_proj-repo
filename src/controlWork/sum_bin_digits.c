#include <stdio.h>

int sumBinDigits(int x);

int main()
{
    int x = 12;
    int x_bin = sumBinDigits(x);
    int y = 25;
    int y_bin = sumBinDigits(y);

    printf("%d\n", (x_bin > y_bin) ? x : y);

    return 0;
}

int sumBinDigits(int x)
{
    int cnt = 0;
    while (x != 0) {
        if (x % 2 == 1) {
            cnt++;
        }
        x /= 2;
    }
    return cnt;
}
