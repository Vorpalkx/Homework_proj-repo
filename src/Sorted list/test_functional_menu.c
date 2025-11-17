#include <stdbool.h>
#include <stdio.h>

#include "test_functional_menu.h"
#include "../List/list.h"
#include "functional_menu.h"

#define COLOR_RED     "\033[0;31m"
#define COLOR_GREEN   "\033[0;32m"
#define COLOR_RESET   "\033[0m"

int test_add_into_empty_list()
{
    SingleLinkedList* list = createList();
    
    suppressing_output();
    add_value(list, 12);
    restoring_output();
    
    bool result;
    result = list->head->data == 12;
    result *= list->tail->data == 12;
    result *= list->tail == list->head;
    
    if (result) {
        printf(COLOR_GREEN "test_add_into_empty_list - passed!\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "test_add_into_empty_list - failed\n" COLOR_RESET);
    }
    
    deleteList(list);
    return result;
}

int test_add_to_begin()
{
    SingleLinkedList* list = createList();
    
    suppressing_output();
    addToBegin(list, 10);
    add_value(list, 30);
    restoring_output();
    
    bool result;
    result = list->head->data == 10;
    result *= list->tail->data == 30;
    
    if (result) {
        printf(COLOR_GREEN "test_add_to_begin - passed!\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "test_add_to_begin - failed\n" COLOR_RESET);
    }
    
    deleteList(list);
    return result;
}

int test_add_to_middle()
{
    SingleLinkedList* list = createList();
    
    suppressing_output();
    addToBegin(list, 10);
    addToEnd(list, 30);
    add_value(list, 20);
    restoring_output();
    
    Node *node = list->head->next;
    
    bool result;
    result = list->head->data == 10;
    result *= list->tail->data == 30;
    result *= node->data == 20;
    
    if (result) {
        printf(COLOR_GREEN "test_add_to_middle - passed!\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "test_add_to_middle - failed\n" COLOR_RESET);
    }
    
    deleteList(list);
    return result;
}

int test_add_to_end()
{
    SingleLinkedList* list = createList();
    
    suppressing_output();
    addToBegin(list, 10);
    add_value(list, 30);
    restoring_output();
    
    bool result;
    result = list->head->data == 10;
    result *= list->tail->data == 30;
    
    if (result) {
        printf(COLOR_GREEN "test_add_to_end - passed!\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "test_add_to_end - failed\n" COLOR_RESET);
    }
    
    deleteList(list);
    return result;
}

int test_add_duplicate()
{
    SingleLinkedList* list = createList();
    
    suppressing_output();
    addToBegin(list, 10);
    addToEnd(list, 30);
    add_value(list, 10);
    restoring_output();
    
    Node *node = list->head->next;
    
    bool result;
    result = list->head->data == 10;
    result *= list->tail->data == 30;
    result *= node->data == 10;
    
    if (result) {
        printf(COLOR_GREEN "test_add_duplicate - passed!\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "test_add_duplicate - failed\n" COLOR_RESET);
    }
    
    deleteList(list);
    return result;
}

int test_delete_single_elem()
{
    SingleLinkedList* list = createList();
    
    suppressing_output();
    addToBegin(list, 10);
    delete_value(list, 10);
    restoring_output();
    
    bool result;
    result = list->head == NULL;
    result *= list->tail == NULL;

    if (result) {
        printf(COLOR_GREEN "test_delete_single_elem - passed!\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "test_delete_single_elem - failed\n" COLOR_RESET);
        deleteList(list);
    }
    
    return result;
}

int test_delete_first_elem()
{
    SingleLinkedList* list = createList();
    
    suppressing_output();
    addToBegin(list, 30);
    addToBegin(list, 20);
    addToBegin(list, 10);
    delete_value(list, 10);
    restoring_output();
    
    bool result;
    result = list->head->data == 20;
    result *= list->tail->data == 30;
    result *= list->head->next == list->tail;

    if (result) {
        printf(COLOR_GREEN "test_delete_first_elem - passed!\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "test_delete_first_elem - failed\n" COLOR_RESET);
    }
    
    deleteList(list);
    return result;
}

int test_delete_last_elem()
{
    SingleLinkedList* list = createList();
    
    suppressing_output();
    addToBegin(list, 30);
    addToBegin(list, 20);
    addToBegin(list, 10);
    delete_value(list, 30);
    restoring_output();
    
    bool result;
    result = list->head->data == 10;
    result *= list->tail->data == 20;
    result *= list->head->next == list->tail;

    if (result) {
        printf(COLOR_GREEN "test_delete_last_elem - passed!\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "test_delete_last_elem - failed\n" COLOR_RESET);
    }
    
    deleteList(list);
    return result;
}

int test_delete_middle_elem()
{
    SingleLinkedList* list = createList();
    
    suppressing_output();
    addToBegin(list, 30);
    addToBegin(list, 20);
    addToBegin(list, 10);
    delete_value(list, 20);
    restoring_output();
    
    bool result;
    result = list->head->data == 10;
    result *= list->tail->data == 30;
    result *= list->head->next == list->tail;

    if (result) {
        printf(COLOR_GREEN "test_delete_middle_elem - passed!\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "test_delete_middle_elem - failed\n" COLOR_RESET);
    }
    
    deleteList(list);
    return result;
}

int test_delete_non_ex_elem()
{
    SingleLinkedList* list = createList();
    
    suppressing_output();
    addToBegin(list, 30);
    addToBegin(list, 20);
    addToBegin(list, 10);
    delete_value(list, 15);
    restoring_output();
    
    Node* node = list->head->next;
    
    bool result;
    result = list->head->data == 10;
    result *= node->data == 20;
    result *= list->tail->data == 30;
    result *= node->next == list->tail;

    if (result) {
        printf(COLOR_GREEN "test_delete_non_ex_elem - passed!\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "test_delete_non_ex_elem - failed\n" COLOR_RESET);
    }
    
    deleteList(list);
    return result;
}

int test_complete_workflow()
{
    SingleLinkedList* list = createList();
    
    suppressing_output();
    add_value(list, 5);
    add_value(list, 1);
    add_value(list, 3);
    restoring_output();
    
    Node* node = list->head->next;
    
    bool sorted;
    sorted = list->head->data == 1;
    sorted *= node->data == 3;
    sorted *= list->tail->data == 5;
    
    if(!sorted) {
        printf(COLOR_RED "test_complete_workflow: sorted - failed\n" COLOR_RESET);
        deleteList(list);
        return sorted;
    }
    
    suppressing_output();
    delete_value(list, 3);
    restoring_output();
    
    bool after_delete;
    after_delete = list->head->data == 1;
    after_delete *= list->tail->data == 5;
    after_delete *= list->head->next == list->tail;
    
    if(!after_delete) {
        printf(COLOR_RED "test_complete_workflow: after_delete - failed\n" COLOR_RESET);
        deleteList(list);
        return after_delete;
    }
    
    suppressing_output();
    add_value(list, 2);
    add_value(list, 4);
    restoring_output();
    
    node = list->head->next;
    bool after_adding;
    after_adding = list->head->data == 1;
    after_adding *= node->data == 2;
    after_adding *= node->next->data == 4;
    after_adding *= list->tail->data == 5;
    
    if(!after_adding) {
        printf(COLOR_RED "test_complete_workflow: after_adding - failed\n" COLOR_RESET);
        deleteList(list);
        return after_adding;
    }
    
    printf(COLOR_GREEN "test_complete_workflow - passed!\n" COLOR_RESET);
    deleteList(list);
    
    return after_adding;
}

int test_edge_cases()
{
    SingleLinkedList* list = createList();
    
    suppressing_output();
    add_value(list, 0);
    add_value(list, -1);
    add_value(list, 1000);
    restoring_output();
    
    Node* node = list->head->next;
    
    bool result;
    result = list->head->data == -1;
    result *= node->data == 0;
    result *= list->tail->data == 1000;
    result *= node->next == list->tail;
    
    suppressing_output();
    delete_value(list, -1);
    delete_value(list, 1000);
    restoring_output();
    
    result *= list->head->data == 0;
    result *= list->head == list->tail;
    
    if (result) {
        printf(COLOR_GREEN "test_edge_cases - passed!\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "test_edge_cases - failed\n" COLOR_RESET);
    }
    
    deleteList(list);
    return result;
}

void run_all_tests()
{
    printf("Running the tests of the sorted list...\n\n");
    
    int total_insert_tests = 4;
    int  insert_tests = test_add_into_empty_list()
                        + test_add_to_begin()
                        + test_add_to_middle()
                        + test_add_duplicate();
    
    if (total_insert_tests == insert_tests) {
        printf("\nAll insertion tests passed!\n\n");
    } else if (insert_tests == 0) {
        printf("\nAll insertion tests failed.\n\n");
    } else {
        printf("\n%d out of %d insertion tests passed\n\n", insert_tests, total_insert_tests);
    }
    
    int total_delete_tests = 5;
    int delete_tests = test_delete_single_elem()
                        + test_delete_first_elem()
                        + test_delete_last_elem()
                        + test_delete_middle_elem()
                        + test_delete_non_ex_elem();
    
    if (total_delete_tests == delete_tests) {
        printf("\nAll delete tests passed!\n\n");
    } else if (delete_tests == 0) {
        printf("\nAll delete tests failed.\n\n");
    } else {
        printf("\n%d out of %d delete tests passed\n\n", delete_tests, total_delete_tests);
    }
    
    int total_integration_tests = 2;
    int integration_tests = test_complete_workflow()
                            + test_edge_cases();
    
    if (total_integration_tests == integration_tests) {
        printf("\nAll integration tests passed!\n");
    } else if (integration_tests == 0) {
        printf("\nAll integration tests failed.\n");
    } else {
        printf("\n%d out of %d integration tests passed\n", integration_tests, total_integration_tests);
    }

    int total_tests = total_insert_tests
                      + total_delete_tests
                      + total_integration_tests;
    
    int passed_tests = insert_tests
                       + delete_tests
                       + integration_tests;
    
    for (int i = 0; i < 90; i++) {
        printf("-");
    }
    if (total_tests == passed_tests) {
        printf("\nAll tests passed!\n");
    } else if (passed_tests == 0) {
        printf("\nAll tests failed.\n");
    } else {
        printf("\n%d out of %d tests passed\n", passed_tests, total_tests);
    }
}

void suppressing_output()
{
    freopen("/dev/null", "w", stdout);
}

void restoring_output()
{
    freopen("/dev/tty", "w", stdout);
}
