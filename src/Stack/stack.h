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

void new_stack(Stack* stack);
bool is_empty(Stack* stack);
void push(Stack* stack, int item);
int pop(Stack* stack);
int peek(Stack* stack);
void delete_stack(Stack* stack);
