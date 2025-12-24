#include <stdio.h>

#include "list.h"

void test_same_length();

int main()
{
    test_same_length();
}

void test_same_length()
{
    List* list1 = createList();
    List* list2 = createList();
    addToEnd(list1, 1);
    addToEnd(list1, 2);
    addToEnd(list1, 3);

    addToEnd(list2, 4);
    addToEnd(list2, 5);
    addToEnd(list2, 6);

    List* list = merge_lists(list1, list2);
    int expected[] = { 1, 4, 2, 5, 3, 6 };
    Node* node = list->head;
    int cnt_right = 0;
    for (int i = 0; i < 6; i++) {
        if (node->data == expected[i]) {
            cnt_right++;
        }
        node = node->next;
    }
    if (cnt_right == 6) {
        printf("test_same_length - passed\n");
    }
}
