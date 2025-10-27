#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct SingleLinkedList {
    Node *head;
    Node *tail;
} SingleLinkedList;

struct SingleLinkedList* new_list()
{
    SingleLinkedList *list = (SingleLinkedList*)malloc(sizeof(SingleLinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

bool is_empty(SingleLinkedList *list)
{
    return list->head == NULL;
}

void add_to_begin(SingleLinkedList *list, int data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    if (is_empty(list)) {
        list->head = new_node;
        list->tail = new_node;
        new_node->next = NULL;
    } else {
        Node *node = list->head;
        list->head = new_node;
        new_node->next = node;
    }
    return;
}

void add_to_end(SingleLinkedList *list, int data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    if (is_empty(list)) {
        list->head = new_node;
        list->tail = new_node;
        new_node->next = NULL;
    } else {;
        list->tail->next = new_node;
        list->tail = new_node;
        new_node->next = NULL;
    }
    return;
}

void add_by_index(SingleLinkedList *list, int data, int index)
{
    if (is_empty(list) || index < 0){
        printf("add_by_index: Index out of range\n");
        return;
    }
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    
    if (index == 0) {
        new_node->next = list->head;
        list->head = new_node;
        return;
    }
    int current_index = 0;
    Node *node = list->head;
    while (node->next != NULL) {
        if (current_index == index - 1) {
            Node *next_node = node->next;
            node->next = new_node;
            new_node->next = next_node;
            return;
        }
        node = node->next;
        current_index++;
    }
    printf("add_by_index: Index out of range\n");
    return;
}

int get_by_index(SingleLinkedList *list, int index)
{
    if (is_empty(list) || index < 0) {
        printf("get_by_index: Index out of range\n");
        return -1;
    }
    
    if (index == 0) {
        Node *node = list->head;
        list->head = node->next;
        if (list->head == NULL)
            list->tail = NULL;
        return node->data;
    }
    
    Node *node = list->head;
    int current_index = 0;
    while (node->next != NULL) {
        if (current_index == index - 1) {
            Node *get_node = node->next;
            node->next = get_node->next;
            if (node->next == NULL)
                list->tail = node;
            return get_node->data;
        }
        node = node->next;
        current_index++;
    }
    printf("get_by_index: Index out of range\n");
    return -1;
}

void remove_by_index(SingleLinkedList *list, int index)
{
    if (is_empty(list) || index < 0) {
        printf("remove_by_index: Index out of range\n");
        return;
    }
    
    if (index == 0) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        if (list->head == NULL)
            list->tail = NULL;
        return;
    }
    
    Node *node = list->head;
    int current_index = 0;
    while (node->next != NULL) {
        if (current_index == index - 1) {
            Node* temp = node->next;
            node->next = node->next->next;
            free(temp);
            if (node->next == NULL)
                list->tail = node;
            return;
        }
        node = node->next;
        current_index++;
    }
    printf("remove_by_index: Index out of range\n");
    return;
}

void print_list(SingleLinkedList *list)
{
    if (is_empty(list)) {
        printf("print_list: List is empty\n");
        return;
    }
    Node *node = list->head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    return;
}

void delete_list(SingleLinkedList *list)
{
    if (is_empty(list)) {
        printf("delete_list: List is empty\n");
        return;
    }
    Node *current = list->head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    return;
}
