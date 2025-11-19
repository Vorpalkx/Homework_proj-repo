#include <stdbool.h>
#include <stdio.h>

#include "../List/list.h"

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int data_entry()
{
    printf("Enter the value: ");
    int value;
    scanf("%d", &value);
    clear_input_buffer();
    return value;
}

void delete_value(SingleLinkedList* list, int value)
{
    int index = searchIndexToRemove(list, value);
    if (index != -1) {
        removeByIndex(list, index);
        printf("The number was successfully deleted\n");
    }
    return;
}

void add_value(SingleLinkedList* list, int value)
{
    int index = searchIndexToAdd(list, value);
    if (index != -1) {
        addByIndex(list, value, index);
    } else {
        addToEnd(list, value);
    }
    printf("The number has been successfully added to the list\n");
    return;
}

void selection_menu(SingleLinkedList* list)
{
    printf("Select one of the options:\n");
    printf("0 – exit\n");
    printf("1 – add a value to the sorted list\n");
    printf("2 – delete the value from the list\n");
    printf("3 – print the list\n\n");
    int c;
    scanf("%d", &c);
    clear_input_buffer();
    switch (c) {
    case 0:
        deleteList(list);
        return;
    case 1:
        add_value(list, data_entry());
        printf("\n");
        selection_menu(list);
        break;
    case 2:
        delete_value(list, data_entry());
        printf("\n");
        selection_menu(list);
        break;
    case 3:
        printf("The list at the moment: ");
        printList(list);
        printf("\n");
        selection_menu(list);
        break;
    default:
        printf("Unknown action - %d\n\n", c);
        selection_menu(list);
    }
}
