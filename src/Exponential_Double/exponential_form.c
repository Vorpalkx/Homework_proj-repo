#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef union Number {
    double value;
    uint64_t bits;
} Number;

typedef struct ExpForm {
    int sign;
    int exponent;
    uint64_t mantissa;
} ExpForm;

ExpForm getExpForm(double data)
{
    Number value;
    value.value = data;

    ExpForm expValue;
    expValue.sign = (int)((value.bits >> 63) & 1);
    expValue.exponent = (int)((value.bits >> 52) & ((1 << 11) - 1));
    expValue.mantissa = value.bits & ((1ULL << 52) - 1);

    return expValue;
}

bool specialCases(ExpForm* expValue)
{
    bool flag = false;
    if (expValue->exponent == 0 && expValue->mantissa == 0) {
        puts("0");
        flag = true;
    } else if (expValue->exponent == (1 << 11) - 1) {
        if (expValue->mantissa == 0) {
            printf("%s\n", expValue->sign ? "-Inf" : "+Inf");
        } else {
            puts("NaN");
        }
        flag = true;
    }

    return flag;
}

void printExpForm(ExpForm* expValue)
{
    int actualExp;
    double mantissaValue;
    if (expValue->exponent == 0) {
        mantissaValue = (double)expValue->mantissa / pow(2.0, 52);
    } else {
        mantissaValue = 1.0 + (double)expValue->mantissa / pow(2.0, 52);
    }
    actualExp = expValue->exponent - 1023;

    printf("%s%1.20f*2^%d\n", expValue->sign ? "-" : "+", mantissaValue, actualExp);
}
