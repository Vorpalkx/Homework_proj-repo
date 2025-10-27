#pragma once

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct SingleLinkedList {
    Node *head;
    Node *tail;
} SingleLinkedList;

void new_list(SingleLinkedList *list);
bool is_empty(SingleLinkedList *list);
void add_to_begin(SingleLinkedList *list, int data);
void add_to_end(SingleLinkedList *list, int data);
void add_by_index(SingleLinkedList *list, int data, int index);
int get_by_index(SingleLinkedList *list, int index);
void remove_by_index(SingleLinkedList *list, int index);
void print_list(SingleLinkedList *list);
void delete_list(SingleLinkedList *list);
