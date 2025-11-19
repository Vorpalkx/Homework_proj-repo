#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Elem {
    int value;
    struct Elem* next;
} Elem;

typedef struct {
    Elem* top;
    int size;
} Stack;

void newStack(Stack* stack)
{
    stack->top = NULL;
    stack->size = 0;
}

bool isEmpty(Stack* stack)
{
    return stack->top == NULL;
}

void push(Stack* stack, int item)
{
    Elem* newElem = malloc(sizeof(Elem));
    if (!newElem) {
        printf("Memory allocation error\n");
        return;
    }
    newElem->value = item;
    newElem->next = stack->top;
    stack->top = newElem;
    stack->size++;
}

int pop(Stack* stack)
{
    if (isEmpty(stack)) {
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
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->value;
}

void deleteStack(Stack* stack)
{
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}
