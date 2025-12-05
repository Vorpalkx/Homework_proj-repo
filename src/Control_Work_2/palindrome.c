#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

void menu(SingleLinkedList* list);
void clearInputBuffer();
bool checkPalindrome(SingleLinkedList* list);

int main()
{
    void* list = createList();
    menu(list);
    return 0;
}

void menu(SingleLinkedList* list)
{
    puts("0 - exit");
    puts("1 - add value");
    puts("2 - clear list");
    puts("3 - check palindrome");
    puts("4 - print list");
    int c;
    scanf("%d", &c);
    clearInputBuffer();
    switch (c) {
    case 0:
        clearList(list);
        free(list);
        return;
    case 1:
        printf("Enter the value: ");
        int data;
        scanf("%d", &data);
        clearInputBuffer();
        addToEnd(list, data);
        printf("\n");
        menu(list);
        break;
    case 2:
        clearList(list);
        printf("\n");
        menu(list);
        break;
    case 3:
        if (checkPalindrome(list)) {
            puts("List is a palindrome");
        } else {
            puts("List is not a palindrome");
        }
        menu(list);
        break;
    case 4:
        printList(list);
        puts("");
        menu(list);
        break;
    default:
        printf("Unknown action - %d\n\n", c);
        menu(list);
    }
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

bool checkPalindrome(SingleLinkedList* list)
{
    if (list->len == 0) {
        puts("List is empty")
        return false;
    }
    int index1 = list->len / 2;
    int index2;
    if (list->len % 2 == 1) {
        index2 = index1;
    } else {
        index2 = index1 - 1;
    }
    do {
        if (searchIndexData(list, index1) == searchIndexData(list, index2)) {
            index1++;
            index2--;
        } else {
            return false;
        }
    } while (index2 != 0);
    
    return true;
}
