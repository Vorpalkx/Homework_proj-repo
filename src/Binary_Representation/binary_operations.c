#include <stdio.h>
#include <stdlib.h>

#include "binary_operations.h"

short* decToBin(int decValue)
{
    int bits = (sizeof(int) * 8) - 1;
    short* binValue = (short*)calloc(bits + 1, sizeof(short));
    for (int i = bits; i >= 0; i--) {
        short bit = (short)((decValue >> i) & 1);
        binValue[bits - i] = bit;
    }
    return binValue;
}

void printBin(short* binValue)
{
    int bits = (sizeof(int) * 8) - 1;
    for (int i = 0; i <= bits; i++) {
        printf("%d", binValue[i]);
    }
    printf("\n");
}

short* addBin(const short* binValue1, const short* binValue2)
{
    int bits = (sizeof(int) * 8) - 1;
    short* amountBin = (short*)calloc(bits + 1, sizeof(short));
    short rememberValue = 0;
    for (int i = bits; i >= 0; i--) {
        short bit = (short)(binValue1[i] + binValue2[i] + rememberValue);
        amountBin[i] = (short)(bit & 1);
        rememberValue = (short)(bit / 2);
    }
    return amountBin;
}

int binToDec(const short* binValue)
{
    int bits = (sizeof(int) * 8) - 1;
    int decValue = 0;
    for (int i = bits; i >= 0; i--) {
        decValue += (binValue[i] * power(2, bits - i));
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
