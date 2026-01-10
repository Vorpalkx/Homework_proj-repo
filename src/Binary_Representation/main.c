#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_operations.h"
#include "binary_operations_tests.h"

int main(int argc, char* argv[])
{
    if (argc > 1 && strcmp(argv[1], "--tests") == 0) {
        runAllTests();
        return 0;
    }

    int data1;
    int data2;
    printf("Enter two values: ");
    scanf("%d %d", &data1, &data2);

    short* binData1 = decToBin(data1);
    short* binData2 = decToBin(data2);
    printBin(binData1);
    printBin(binData2);

    short* amountBin = addBin(binData1, binData2);
    printBin(amountBin);

    int amount = binToDec(amountBin);
    printf("Amount = %d\n", amount);

    free(binData1);
    free(binData2);
    free(amountBin);

    return 0;
}
