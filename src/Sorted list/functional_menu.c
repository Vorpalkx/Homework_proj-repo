#include <stdio.h>
#include <stdbool.h>

#include "../List/list.h"

void clear_input_buffer()
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void delete_value(SingleLinkedList *list)
{
    printf("Enter the number you want to delete: ");
    int value;
    scanf("%d", &value);
    clear_input_buffer();

    Node *node = list->head;
    int index = 0;
    while (node != NULL) {
        if (node->data == value) {
            remove_by_index(list, index);
            printf("The number was successfully deleted\n");
            break;
        }
        node = node->next;
        index++;
    }

    if (node == NULL) {
        printf("There is no such number in the list\n");
    }

    return;
}

void add_value(SingleLinkedList *list)
{
    printf("Enter the value: ");
    int value;
    scanf("%d", &value);
    clear_input_buffer();
    
    Node* node = list->head;
    if (is_empty(list) || node->data > value) {
        add_to_begin(list, value);
        printf("The number has been successfully added to the list\n");
        return;
    }
    int index = 0;
    while (node != NULL) {
        if (node->data > value){
            add_by_index(list, value, index);
            printf("The number has been successfully added to the list\n");
            return;
        }
        node = node->next;
        index++;
    }
    add_to_end(list, value);
    return;
}

void selection_menu(SingleLinkedList *list)
{
    printf("Select one of the options:\n");
    printf("0 – exit\n");
    printf("1 – add a value to the sorted list\n");
    printf("2 – delete the value from the list\n");
    printf("3 – print the list\n\n");
    int c;
    scanf("%d", &c);
    clear_input_buffer();
    switch(c) {
        case 0:
            return;
        case 1:
            add_value(list);
            printf("\n");
            selection_menu(list);
            break;
        case 2:
            delete_value(list);
            printf("\n");
            selection_menu(list);
            break;
        case 3:
            printf("The list at the moment: ");
            print_list(list);
            printf("\n");
            selection_menu(list);
            break;
        default:
            printf("Unknown action - %d\n\n", c);
            selection_menu(list);
    }
}
