#include <stdio.h>

#include "../Stack/stack.h"
#include "string_filling.h"
#include "bracket_balance.h"

int main()
{
    Stack bracket_stack;
    new_stack(&bracket_stack);
    int *string = string_filling();
    bracket_balance(&bracket_stack, string);
    return 0;
}
