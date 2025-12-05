#include <stdbool.h>
#include <stdio.h>

int binToDec(const bool* binNum);
int power(int data, int degree);

int main()
{
    bool binaryNumber[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1};
    int maxDecNum = 0;
    for (int i = 0; i < 32; i++) {
        maxDecNum = (binToDec(binaryNumber) > maxDecNum) ? binToDec(binaryNumber) : maxDecNum;
        for (int j = 0; j < 31; j++) {
            bool data = binaryNumber[j];
            binaryNumber[j] = binaryNumber[j + 1];
            binaryNumber[j + 1] = data;
        }
    }
    printf("%d\n", maxDecNum);
    return maxDecNum;
}

int binToDec(const bool* binNum)
{
    int bits = (sizeof(int) * 8) - 1;
    int decValue = 0;
    for (int i = bits; i >= 0; i--) {
        decValue += (binNum[i] * power(2, bits - i));
    }
    return decValue;
}

int power(int data, int degree)
{
    if (degree == 0) {
        return 1;
    }
    int number = data;
    for (int i = degree - 1; i > 0; i--) {
        number *= data;
    }
    return number;
}
