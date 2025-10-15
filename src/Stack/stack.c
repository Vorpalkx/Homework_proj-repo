#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Elem {
    int value;
    struct Elem* next;
} Elem;

typedef struct {
    Elem* top;
    int size;
} Stack;

void new_stack(Stack* stack)
{
    stack->top = NULL;
    stack->size = 0;
}

bool is_empty(Stack* stack)
{
    return stack->top == NULL;
}

void push(Stack* stack, int item)
{
    Elem* new_elem = malloc(sizeof(Elem));
    if (!new_elem) {
        printf("Memory allocation error\n");
        return;
    }
    new_elem->value = item;
    new_elem->next = stack->top;
    stack->top = new_elem;
    stack->size++;
}

int pop(Stack* stack)
{
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    Elem* pointer = stack->top;
    int item = pointer->value;
    stack->top = pointer->next;
    free(pointer);
    stack->size--;
    return item;
}

int peek(Stack* stack)
{
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->value;
}

void delete_stack(Stack* stack)
{
    while (!is_empty(stack)) {
        pop(stack);
    }
    free(stack);
}
