#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef union Number {
    double value;
    uint64_t bits;
} Number;

typedef struct ExpForm {
    int sign;
    int exponent;
    uint64_t mantissa;
} ExpForm;

ExpForm getExpForm(double data);
bool specialCases(ExpForm* expValue);
void printExpForm(ExpForm* expValue);
