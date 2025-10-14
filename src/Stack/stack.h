#pragma once

#include <stdbool.h>

typedef struct Elem {
    int value;
    struct Elem* next;
} Elem;

typedef struct {
    Elem* top;
    int size;
} Stack;

void newStack(Stack* stack);
bool isEmpty(Stack* stack);
void push(Stack* stack, int item);
int pop(Stack* stack);
int peek(Stack* stack);
void deleteStack(Stack* stack);
