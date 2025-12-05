#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

struct SingleLinkedList* createList()
{
    SingleLinkedList* list = (SingleLinkedList*)malloc(sizeof(SingleLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->len = 0;
    return list;
}

bool isEmpty(SingleLinkedList* list)
{
    return list->head == NULL;
}

void addToEnd(SingleLinkedList* list, int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    if (isEmpty(list)) {
        list->head = new_node;
        list->tail = new_node;
        new_node->next = NULL;
        new_node->index = 0;
        list->len = 1;
    } else {
        list->tail->next = new_node;
        new_node->index = list->tail->index + 1;
        list->tail = new_node;
        new_node->next = NULL;
        list->len++;
    }
}

int searchIndexData(SingleLinkedList* list, int index)
{
    Node* node = list->head;
    while (node->next != NULL) {
        if (node->index == index) {
            return node->data;
        }
        node = node->next;
    }
    puts("Index out of range");
    return 0;
}

void clearList(SingleLinkedList* list)
{
    Node* node = list->head;
    if (isEmpty(list)) {
        return;
    }
    while (node != NULL) {
        Node* nextNode = node->next;
        free(node);
        node = nextNode;
    }
    list->tail = NULL;
    list->head = NULL;
    list->len = 0;
}

void printList(SingleLinkedList* list)
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
