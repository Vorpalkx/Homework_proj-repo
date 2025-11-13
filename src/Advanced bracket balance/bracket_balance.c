#include <stdio.h>

#include "../Stack/stack.h"

void bracket_balance(Stack* stack, int* string)
{
    int counter = string[0];
    char bracket[] = {'(', ')', '[', ']', '{', '}'};
    for (int i = 1; i < counter; i++) {
        for (int j = 0; j < 6; j++) {
            if (string[i] == bracket[j]) {
                // Checking that the bracket is opening
                if (j % 2 == 0) {
                    push(stack, string[i]);
                } else {
                    if (is_empty(stack)) {
                        printf("The balance of the brackets is not respected\n");
                        return;
                    }

                    // Checking the matching of brackets
                    char top_el = peek(stack);
                    if (top_el == bracket[j-1]) {
                        pop(stack);
                    } else {
                        printf("The balance of the brackets is not respected\n");
                        return;
                    }
                }
                break;
            }
        }
    }

    // Checking that there are no brackets left in the stack
    if (is_empty(stack)) {
        printf("The balance of the brackets is respected\n");
    } else {
        printf("The balance of the brackets is not respected\n");
    }
    return;
}
