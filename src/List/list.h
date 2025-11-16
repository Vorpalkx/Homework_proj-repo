#pragma once

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct SingleLinkedList {
    Node *head;
    Node *tail;
} SingleLinkedList;

struct SingleLinkedList* createList();
bool isEmpty(SingleLinkedList *list);
void addToBegin(SingleLinkedList *list, int data);
void addToEnd(SingleLinkedList *list, int data);
void addByIndex(SingleLinkedList *list, int data, int index);
int getByIndex(SingleLinkedList *list, int index);
void removeByIndex(SingleLinkedList *list, int index);
void printList(SingleLinkedList *list);
void deleteList(SingleLinkedList *list);
