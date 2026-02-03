#pragma once

#include <stdbool.h>

typedef struct Node {
   int data;
   struct Node* next;
} Node;

typedef struct CyclicList {
   Node* head;
   Node* tail;
} CyclicList;

struct CyclicList* new_cycl_list();
bool cycl_list_is_empty(CyclicList* list);
void add_to_end_cycl_list(CyclicList* list, int data);
void remove_by_index_cycl_list(CyclicList* list, int index);
void delete_cycl_list(CyclicList* list);
int cycl_list_length(CyclicList* list);
