#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "binary_operations.h"
#include "binary_operations_tests.h"

int compareBinArrays(const short* arr1, const short* arr2)
{
    int length = sizeof(int) * 8;
    for (int i = 0; i < length; i++) {
        if (arr1[i] != arr2[i]) {
            return 0;
        }
    }
    return 1;
}

void testDecToBin()
{
    printf("Testing decToBin...\n");

    // Test 1: Zero
    short* zero = decToBin(0);
    short expectedZero[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    assert(compareBinArrays(zero, expectedZero));
    free(zero);

    // Test 2: Positive number
    short* five = decToBin(5);
    short expectedFive[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 };
    assert(compareBinArrays(five, expectedFive));
    free(five);

    // Test 3: Negative number
    short* negativeEight = decToBin(-8);
    short expectedNegativeEight[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 };
    assert(compareBinArrays(negativeEight, expectedNegativeEight));
    free(negativeEight);

    // Test 4: Maximum positive for 32-bit
    short* maxPos = decToBin(2147483647);
    short expectedMaxPos[] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    assert(compareBinArrays(maxPos, expectedMaxPos));
    free(maxPos);

    // Test 5: Minimum negative for 32-bit
    short* minPos = decToBin(-2147483648);
    short expectedMinPos[] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    assert(compareBinArrays(minPos, expectedMinPos));
    free(minPos);

    printf("decToBin tests passed!\n\n");
}

void testBinToDec()
{
    printf("Testing binToDec...\n");

    // Test 1: Zero
    short zeroBin[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    assert(binToDec(zeroBin) == 0);

    // Test 2: Positive number
    short fiveBin[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 };
    assert(binToDec(fiveBin) == 5);

    // Test 3: Negative number
    short negativeEightBin[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 };
    assert(binToDec(negativeEightBin) == -8);

    // Test 4: Maximum positive number
    short maxBin[] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    assert(binToDec(maxBin) == 2147483647);

    // Test 5: Minimum negative number
    short minBin[] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    assert(binToDec(minBin) == -2147483648);

    printf("binToDec tests passed!\n\n");
}

void testAddBin()
{
    printf("Testing addBin...\n");

    // Test 1: Two positive numbers
    short* five = decToBin(5);
    short* three = decToBin(3);
    short* eight = addBin(five, three);
    short expectedEight[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 };
    assert(compareBinArrays(eight, expectedEight));
    free(five);
    free(three);
    free(eight);

    // Test 2: Two negative numbers
    short* negativeThree = decToBin(-3);
    short* negativeTwo = decToBin(-2);
    short* negativeFive = addBin(negativeThree, negativeTwo);
    short expectedNegativeFive[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1 };
    assert(compareBinArrays(negativeFive, expectedNegativeFive));
    free(negativeThree);
    free(negativeTwo);
    free(negativeFive);

    // Test 3: Negative with positive
    short* nine = decToBin(9);
    short* negativeEight = decToBin(-8);
    short* negativeOne = addBin(nine, negativeEight);
    short expectedNegativeOne[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
    assert(compareBinArrays(negativeOne, expectedNegativeOne));
    free(nine);
    free(negativeEight);
    free(negativeOne);

    printf("addBin tests passed!\n\n");
}

void runAllTests()
{
    printf("Starting binary operations tests...\n\n");

    testDecToBin();
    testBinToDec();
    testAddBin();

    printf("All tests completed!\n");
}
