#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
   int data;
   struct Node* next;
} Node;

typedef struct CyclicList {
   Node* head;
   Node* tail;
} CyclicList;

struct CyclicList* new_cycl_list()
{
   CyclicList* list = (CyclicList*)malloc(sizeof(CyclicList));
   list->head = NULL;
   list->tail = NULL;
   return list;
}

bool cycl_list_is_empty(CyclicList* list)
{
   return (list->head == NULL);
}

void add_to_end_cycl_list(CyclicList* list, int data)
{
   Node* new_node = (Node*)malloc(sizeof(Node));
   new_node->data = data;
 
   if (cycl_list_is_empty(list)) {
       list->head = new_node;
       list->tail = new_node;
       new_node->next = new_node;
   } else {
       list->tail->next = new_node;
       list->tail = new_node;
       new_node->next = list->head;
   }
}

void remove_by_index_cycl_list(CyclicList* list, int index)
{
   if (cycl_list_is_empty(list)) {
       printf("remove_by_index_cycl_list: List is empty\n");
       return;
   }

   Node* node = list->head;
   if (node == node->next) {
       free(node);
       list->head = NULL;
       list->tail = NULL;
       return;
   }
   
   Node *current = list->head;
   Node *prev = list->tail;
   
   for (int i = 0; i < index; i++) {
       prev = current;
       current = current->next;
   }

   prev->next = current->next;
   
   if (current == list->head) {
       list->head = current->next;
   }
   if (current == list->tail) {
       list->tail = prev;
   }
}

void delete_cycl_list(CyclicList* list)
{
   if (cycl_list_is_empty(list)) {
       printf("delete_cycl_list: List is empty\n");
       return;
   }
   
   Node* current = list->head;
   while (current != list->tail) {
       Node *next = current->next;
       free(current);
       current = next;
   }
   free(current);
   free(list);
}

int cycl_list_length(CyclicList* list)
{
   if (cycl_list_is_empty(list)) return 0;
   
   int count = 0;
   Node* current = list->head;
   do {
       count++;
       current = current->next;
   } while (current != list->head);
   
   return count;
}
