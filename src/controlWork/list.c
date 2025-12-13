#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
} List;

struct List* createList()
{
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

bool isEmpty(List* list)
{
    return list->head == NULL;
}

void addToEnd(List* list, int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    if (isEmpty(list)) {
        list->head = new_node;
        list->tail = new_node;
        new_node->next = NULL;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
        new_node->next = NULL;
    }
    return;
}

void printList(List* list)
{
    if (isEmpty(list)) {
        printf("printList: List is empty\n");
        return;
    }
    Node* node = list->head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    return;
}

void deleteList(List* list)
{
    if (isEmpty(list)) {
        printf("deleteList: List is empty\n");
        return;
    }
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    return;
}

struct List* merge_lists(List* list1, List* list2)
{
    Node* curr1 = list1->head;
    Node* curr2 = list2->head;
    Node* next1 = curr1->next;
    Node* next2 = curr2->next;
    while (next1 != NULL && next2 != NULL) {
        curr1->next = curr2;
        curr2->next = next1;
        curr1 = next1;
        curr2 = next2;
        next1 = curr1->next;
        next2 = curr2->next;
    }
    if (next1 == NULL && next2 == NULL) {
        curr1->next = curr2;
    } else if (next1 == NULL && next2 != NULL) {
        curr1->next = curr2;
        curr2->next = next2;
    } else if (next2 == NULL && next1 != NULL) {
        curr1->next = curr2;
        curr2->next = next1;
    }
    return list1;
}
