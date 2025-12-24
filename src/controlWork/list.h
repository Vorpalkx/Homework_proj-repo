#pragma once

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
} List;

struct List* createList();
bool isEmpty(List* list);
void addToEnd(List* list, int data);
void printList(List* list);
void deleteList(List* list);
struct List* merge_lists(List* list1, List* list2);
