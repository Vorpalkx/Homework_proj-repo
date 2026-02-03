#pragma once

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
    int index;
} Node;

typedef struct SingleLinkedList {
    Node* head;
    Node* tail;
    int len;
} SingleLinkedList;

struct SingleLinkedList* createList();
bool isEmpty(SingleLinkedList* list);
void addToEnd(SingleLinkedList* list, int data);
int searchIndexData(SingleLinkedList* list, int index);
void clearList(SingleLinkedList* list);
void printList(SingleLinkedList* list);
