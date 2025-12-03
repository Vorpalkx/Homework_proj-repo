#include <stdio.h>

#include "../Stack/stack.h"
#include "bracket_balance.h"
#include "string_filling.h"

int main()
{
    // Stack declaration
    Stack bracketStack;
    newStack(&bracketStack);

    // Filling in a dynamic array using the keyboard
    int* string = stringFilling();

    // Checking the string for bracket balance
    bracketBalance(&bracketStack, string);

    return 0;
}
