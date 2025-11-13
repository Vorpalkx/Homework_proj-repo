#include <stdio.h>

#include "../Stack/stack.h"
#include "string_filling.h"
#include "bracket_balance.h"

int main()
{
    // Stack declaration
    Stack bracket_stack;
    new_stack(&bracket_stack);

    // Filling in a dynamic array using the keyboard
    int *string = string_filling();

    // Checking the string for bracket balance
    bracket_balance(&bracket_stack, string);

    return 0;
}
