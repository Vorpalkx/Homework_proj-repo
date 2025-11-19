#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "../Stack/stack.h"
#include "filling_expression.h"

int get_operator_prec(char op);

int main()
{
    // Stack initialization
    Stack stack;
    new_stack(&stack);

    // Filling in an expression
    char* expression = filling_expression();
    int number_characters = strlen(expression);

    // Creating an output queue
    int output[number_characters];
    int counter = 0;

    // Dijkstra's shunting yard algorithm
    for (int i = 0; i < number_characters; i++) {
        int token = expression[i];
        if (isdigit(token)) {
            output[counter] = token;
            counter++;
        } else if (token == '(') {
            push(&stack, token);
        } else if (token == ')') {
            while (peek(&stack) != '(') {
                output[counter] = pop(&stack);
                counter++;
                if (is_empty(&stack)) {
                    printf("The bracket is missing in the expression+\n");
                    return 0;
                }
            }
            pop(&stack);
        } else {
            while ((get_operator_prec(peek(&stack)) >= get_operator_prec(token)) && !is_empty(&stack)) {
                output[counter] = pop(&stack);
                counter++;
            }
            push(&stack, token);
        }
    }
    while (!is_empty(&stack)) {
        if (peek(&stack) == '(') {
            printf("The bracket is missing in the expression\n");
            return 0;
        }
        output[counter] = pop(&stack);
        counter++;
    }

    // Displaying the queue on the screen
    for (int i = 0; i < counter; i++)
        printf("%c ", output[i]);
    printf("\n");

    return 0;
}

// Returns the priority of the operation
int get_operator_prec(char op)
{
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}
