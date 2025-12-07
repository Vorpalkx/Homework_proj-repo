#include <stdio.h>

#include "exponential_form.h"

int main()
{
    double value;
    printf("Enter a number: ");
    scanf("%lf", &value);

    ExpForm expValue = getExpForm(value);
    if (specialCases(&expValue)) {
        return 0;
    }

    printf("Result: ");
    printExpForm(&expValue);

    return 0;
}
