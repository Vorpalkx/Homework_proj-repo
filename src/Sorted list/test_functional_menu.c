#include <stdbool.h>
#include <stdio.h>

#include "test_functional_menu.h"
#include "../List/list.h"
#include "functional_menu.h"

#define COLOR_RED     "\033[0;31m"
#define COLOR_GREEN   "\033[0;32m"
#define COLOR_RESET   "\033[0m"

int testAddIntoEmptyList()
{
    SingleLinkedList* list = createList();

    suppressingOutput();
    add_value(list, 12);
    restoringOutput();

    bool result;
    result = list->head->data == 12;
    result *= list->tail->data == 12;
    result *= list->tail == list->head;

    if (result) {
        printf(COLOR_GREEN "testAddIntoEmptyList - passed!\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "testAddIntoEmptyList - failed\n" COLOR_RESET);
    }

    deleteList(list);
    return result;
}

int testAddToBegin()
{
    SingleLinkedList* list = createList();

    suppressingOutput();
    addToBegin(list, 10);
    add_value(list, 30);
    restoringOutput();

    bool result;
    result = list->head->data == 10;
    result *= list->tail->data == 30;

    if (result) {
        printf(COLOR_GREEN "testAddToBegin - passed!\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "testAddToBegin - failed\n" COLOR_RESET);
    }

    deleteList(list);
    return result;
}

int testAddToMiddle()
{
    SingleLinkedList* list = createList();

    suppressingOutput();
    addToBegin(list, 10);
    addToEnd(list, 30);
    add_value(list, 20);
    restoringOutput();

    Node* node = list->head->next;

    bool result;
    result = list->head->data == 10;
    result *= list->tail->data == 30;
    result *= node->data == 20;

    if (result) {
        printf(COLOR_GREEN "testAddToMiddle - passed!\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "testAddToMiddle - failed\n" COLOR_RESET);
    }

    deleteList(list);
    return result;
}

int testAddToEnd()
{
    SingleLinkedList* list = createList();

    suppressingOutput();
    addToBegin(list, 10);
    add_value(list, 30);
    restoringOutput();

    bool result;
    result = list->head->data == 10;
    result *= list->tail->data == 30;

    if (result) {
        printf(COLOR_GREEN "testAddToEnd - passed!\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "testAddToEnd - failed\n" COLOR_RESET);
    }

    deleteList(list);
    return result;
}

int testAddDuplicate()
{
    SingleLinkedList* list = createList();

    suppressingOutput();
    addToBegin(list, 10);
    addToEnd(list, 30);
    add_value(list, 10);
    restoringOutput();

    Node* node = list->head->next;

    bool result;
    result = list->head->data == 10;
    result *= list->tail->data == 30;
    result *= node->data == 10;

    if (result) {
        printf(COLOR_GREEN "testAddDuplicate - passed!\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "testAddDuplicate - failed\n" COLOR_RESET);
    }

    deleteList(list);
    return result;
}

int testDeleteSingleElem()
{
    SingleLinkedList* list = createList();

    suppressingOutput();
    addToBegin(list, 10);
    delete_value(list, 10);
    restoringOutput();

    bool result;
    result = list->head == NULL;
    result *= list->tail == NULL;

    if (result) {
        printf(COLOR_GREEN "testDeleteSingleElem - passed!\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "testDeleteSingleElem - failed\n" COLOR_RESET);
    }

    deleteList(list);
    return result;
}

int testDeleteFirstElem()
{
    SingleLinkedList* list = createList();

    suppressingOutput();
    addToBegin(list, 30);
    addToBegin(list, 20);
    addToBegin(list, 10);
    delete_value(list, 10);
    restoringOutput();

    bool result;
    result = list->head->data == 20;
    result *= list->tail->data == 30;
    result *= list->head->next == list->tail;

    if (result) {
        printf(COLOR_GREEN "testDeleteFirstElem - passed!\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "testDeleteFirstElem - failed\n" COLOR_RESET);
    }

    deleteList(list);
    return result;
}

int testDeleteLastElem()
{
    SingleLinkedList* list = createList();

    suppressingOutput();
    addToBegin(list, 30);
    addToBegin(list, 20);
    addToBegin(list, 10);
    delete_value(list, 30);
    restoringOutput();

    bool result;
    result = list->head->data == 10;
    result *= list->tail->data == 20;
    result *= list->head->next == list->tail;

    if (result) {
        printf(COLOR_GREEN "testDeleteLastElem - passed!\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "testDeleteLastElem - failed\n" COLOR_RESET);
    }

    deleteList(list);
    return result;
}

int testDeleteMiddleElem()
{
    SingleLinkedList* list = createList();

    suppressingOutput();
    addToBegin(list, 30);
    addToBegin(list, 20);
    addToBegin(list, 10);
    delete_value(list, 20);
    restoringOutput();

    bool result;
    result = list->head->data == 10;
    result *= list->tail->data == 30;
    result *= list->head->next == list->tail;

    if (result) {
        printf(COLOR_GREEN "testDeleteMiddleElem - passed!\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "testDeleteMiddleElem - failed\n" COLOR_RESET);
    }

    deleteList(list);
    return result;
}

int testDeleteNonExElem()
{
    SingleLinkedList* list = createList();

    suppressingOutput();
    addToBegin(list, 30);
    addToBegin(list, 20);
    addToBegin(list, 10);
    delete_value(list, 15);
    restoringOutput();

    Node* node = list->head->next;

    bool result;
    result = list->head->data == 10;
    result *= node->data == 20;
    result *= list->tail->data == 30;
    result *= node->next == list->tail;

    if (result) {
        printf(COLOR_GREEN "testDeleteNonExElem - passed!\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "testDeleteNonExElem - failed\n" COLOR_RESET);
    }

    deleteList(list);
    return result;
}

int testCompleteWorkflow()
{
    SingleLinkedList* list = createList();

    suppressingOutput();
    add_value(list, 5);
    add_value(list, 1);
    add_value(list, 3);
    restoringOutput();

    Node* node = list->head->next;

    bool sorted;
    sorted = list->head->data == 1;
    sorted *= node->data == 3;
    sorted *= list->tail->data == 5;

    if(!sorted) {
        printf(COLOR_RED "testCompleteWorkflow: sorted - failed\n" COLOR_RESET);
        deleteList(list);
        return sorted;
    }

    suppressingOutput();
    delete_value(list, 3);
    restoringOutput();

    bool after_delete;
    after_delete = list->head->data == 1;
    after_delete *= list->tail->data == 5;
    after_delete *= list->head->next == list->tail;

    if(!after_delete) {
        printf(COLOR_RED "testCompleteWorkflow: after_delete - failed\n" COLOR_RESET);
        deleteList(list);
        return after_delete;
    }

    suppressingOutput();
    add_value(list, 2);
    add_value(list, 4);
    restoringOutput();

    node = list->head->next;
    bool after_adding;
    after_adding = list->head->data == 1;
    after_adding *= node->data == 2;
    after_adding *= node->next->data == 4;
    after_adding *= list->tail->data == 5;

    if(!after_adding) {
        printf(COLOR_RED "testCompleteWorkflow: after_adding - failed\n" COLOR_RESET);
        deleteList(list);
        return after_adding;
    }

    printf(COLOR_GREEN "testCompleteWorkflow - passed!\n" COLOR_RESET);
    deleteList(list);

    return after_adding;
}

int testEdgeCases()
{
    SingleLinkedList* list = createList();

    suppressingOutput();
    add_value(list, 0);
    add_value(list, -1);
    add_value(list, 1000);
    restoringOutput();

    Node* node = list->head->next;

    bool result;
    result = list->head->data == -1;
    result *= node->data == 0;
    result *= list->tail->data == 1000;
    result *= node->next == list->tail;

    suppressingOutput();
    delete_value(list, -1);
    delete_value(list, 1000);
    restoringOutput();

    result *= list->head->data == 0;
    result *= list->head == list->tail;

    if (result) {
        printf(COLOR_GREEN "testEdgeCases - passed!\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "testEdgeCases - failed\n" COLOR_RESET);
    }

    deleteList(list);
    return result;
}

void runAllTests()
{
    printf("Running the tests of the sorted list...\n\n");

    int total_insert_tests = 5;
    int  insert_tests = testAddIntoEmptyList()
                        + testAddToBegin()
                        + testAddToMiddle()
                        + testAddToEnd()
                        + testAddDuplicate();

    if (total_insert_tests == insert_tests) {
        printf("\nAll insertion tests passed!\n\n");
    } else if (insert_tests == 0) {
        printf("\nAll insertion tests failed.\n\n");
    } else {
        printf("\n%d out of %d insertion tests passed\n\n", insert_tests, total_insert_tests);
    }

    int total_delete_tests = 5;
    int delete_tests = testDeleteSingleElem()
                        + testDeleteFirstElem()
                        + testDeleteLastElem()
                        + testDeleteMiddleElem()
                        + testDeleteNonExElem();

    if (total_delete_tests == delete_tests) {
        printf("\nAll delete tests passed!\n\n");
    } else if (delete_tests == 0) {
        printf("\nAll delete tests failed.\n\n");
    } else {
        printf("\n%d out of %d delete tests passed\n\n", delete_tests, total_delete_tests);
    }

    int total_integration_tests = 2;
    int integration_tests = testCompleteWorkflow()
                            + testEdgeCases();

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

void suppressingOutput()
{
    freopen("/dev/null", "w", stdout);
}

void restoringOutput()
{
    freopen("/dev/tty", "w", stdout);
}
